/**

Spelling Checker
Problem Description

Given an array of words A (dictionary) and another array B (which contain some words).

You have to return the binary array (of length |B|) as the answer where 1 denotes that the word is present in the dictionary and 0 denotes it is not present.

Formally, for each word in B, you need to return 1 if it is present in Dictionary and 0 if it is not.

Such problems can be seen in real life when we work on any online editor (like Google Documnet), if the word is not valid it is underlined by a red line.

NOTE: Try to do this in O(n) time complexity.



Problem Constraints
1 <= |A| <= 1000

1 <= sum of all strings in A <= 50000

1 <= |B| <= 1000



Input Format
First argument is array of strings A.

First argument is array of strings B.



Output Format
Return the binary array of integers according to the given format.



Example Input
Input 1:

A = [ "hat", "cat", "rat" ]
B = [ "cat", "ball" ]
Input 2:

A = [ "tape", "bcci" ]
B = [ "table", "cci" ]


Example Output
Output 1:

[1, 0]
Output 2:

[0, 0]


Example Explanation
Explanation 1:

Only "cat" is present in the dictionary.
Explanation 2:

None of the words are present in the dictionary.




**/

class Trie {
public:
    struct Node {
        Node* arr[26];
        bool isEnd;
        int cnt;

        Node() {
            for (int i = 0; i < 26; i++) {
                arr[i] = NULL;
            }
            isEnd = false;
            cnt = 1;
        }
    };

    char base = 'a';
    Node *root;
    Trie() {root = new Node(); }

    void insert (const string& s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->arr[ch - base])
                cur->arr[ch - base] = new Node();
            cur = cur->arr[ch - base];
        }
        cur->isEnd = true;
    }

    bool search(const string& s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->arr[ch - base])
                return false;
            cur = cur->arr[ch - base];
        }
        return (cur != NULL and cur->isEnd);
    }

    string uniquePrefix(string s) {
        string ans = "";
        Node *cur = root;
        for (char c : s) {
            ans += c;
            if (cur->arr[c - 'a']->cnt == 1) {
                break;
            }
            cur = cur->arr[c - 'a'];
        }
        return ans;
    }

};

vector<int> Solution::solve(vector<string> &a, vector<string> &b) {

    Trie t;
    for (auto &x : a) {
        t.insert(x);
    }

    vector<int> ans;
    for (auto &x : b) {
        if (t.search(x)) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}



