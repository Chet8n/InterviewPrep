/**

Prefix and Suffix
Problem Description

Given a list of N words denoted by string array A of size N.

You have to answer Q queries denoted by string array B, for each query you have a string S of size M, find the number of words in the list A which have string S as a prefix and suffix.

NOTE: The size M for all strings in the queries remains same.



Problem Constraints
1 <= N <= 105

1 <= |A[i]| <= 1000

1 <= Q, M <= 1000

Sum of length of all N words <= 106



Input Format
First argument is a string array A of size N denoting the list of words.

Second argument is a string array B of size Q denoting the queries.



Output Format
Return an integer array of size Q denoting the answer of each query.



Example Input
Input 1:

 A = ["ababa", "aabbvaab", "aecdsaaec", "abaaxbqaba"]
 B = ["aba", "aec", "abb", "aab"]
Input 2:

 A = ["cazqzqcaz", "cadssac", "caz"]
 B = ["caz", "cad"]


Example Output
Output 1:

 [2, 1, 0, 1]
Output 2:

 [2, 0]


Example Explanation
Explanation 1:

 2 word "ababa" and "abaaxbqaba" has both prefix and suffix "aba".
 1 word "aecdsaaec" has both prefix and suffix "aec".
 No word has both prefix and suffix "abb".
 1 word "aabbvaab" has both prefix and suffix "aab".
Explanation 2:

 2 word "cazqzqcaz" and "caz" has both prefix and suffix "caz".
 No word has both prefix and suffix "cad".


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

    void insert (const string &s) {
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

    int search(const string &s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->arr[ch - base])
                return 0;
            cur = cur->arr[ch - base];
        }
        if (cur != NULL) {
            return cur->cnt;
        }
        return 0;
    }

};

vector<int> Solution::solve(vector<string> &a, vector<string> &b) {

    vector<int> ans;
    int n = a.size();
    int m = b[0].size();

    Trie t;
    for (auto &x : a) {
        if (x.length() >= m) {
            string cur = "";
            int k = x.length();
           
            string c = x.substr(k - m, m);
            string d = x.substr(0, m);
            if(c != d){
                continue;
            }
            t.insert(c);
        }
    }

    for (auto &x : b) {
        string cur = x;
        int here = t.search(cur);
        ans.push_back(here);
    }

    return ans;
}



