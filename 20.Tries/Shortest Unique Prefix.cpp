/**

Shortest Unique Prefix
Problem Description

Given a list of N words. Find shortest unique prefix to represent each word in the list.

NOTE: Assume that no word is prefix of another. In other words, the representation is always possible



Problem Constraints
1 <= Sum of length of all words <= 106



Input Format
First and only argument is a string array of size N.



Output Format
Return a string array B where B[i] denotes the shortest unique prefix to represent the ith word.



Example Input
Input 1:

 A = ["zebra", "dog", "duck", "dove"]
Input 2:

A = ["apple", "ball", "cat"]


Example Output
Output 1:

 ["z", "dog", "du", "dov"]
Output 2:

 ["a", "b", "c"]


Example Explanation
Explanation 1:

 Shortest unique prefix of each word is:
 For word "zebra", we can only use "z" as "z" is not any prefix of any other word given.
 For word "dog", we have to use "dog" as "d" and "do" are prefixes of "dov".
 For word "du", we have to use "du" as "d" is prefix of "dov" and "dog".
 For word "dov", we have to use "dov" as "d" and do" are prefixes of "dog".

Explanation 2:

 "a", "b" and c" are not prefixes of any other word. So, we can use of first letter of each to represent.

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
            else
                cur->arr[ch - base]->cnt += 1;
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

vector<string> Solution::prefix(vector<string> &a) {

    Trie t;
    for (auto &x : a) {
        t.insert(x);
    }

    vector<string> ans;

    for (auto &x : a) {
        string here = t.uniquePrefix(x);
        ans.push_back(here);
    }
    return ans;
}

