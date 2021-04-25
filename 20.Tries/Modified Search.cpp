/**

Modified Search
Problem Description

Given two arrays of strings A of size N and B of size M.

Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using exactly one modification in B[i], Else C[i] = '0'.

NOTE: modification is defined as converting a character into another character.



Problem Constraints
1 <= N <= 30000

1 <= M <= 2500

1 <= length of any string either in A or B <= 20

strings contains only lowercase alphabets



Input Format
First argument is the string arrray A.

Second argument is the string array B.



Output Format
Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using one modification in B[i], Else C[i] = '0'.



Example Input
Input 1:

 A = [data, circle, cricket]
 B = [date, circel, crikket, data, circl]
Input 2:

 A = [hello, world]
 B = [hella, pello, pella]


Example Output
Output 1:

 "10100"
Output 2:

 "110"


Example Explanation
Explanation 1:

 1. date = dat*(can be found in A)
 2. circel =(cannot be found in A using exactly one modification)
 3. crikket = cri*ket(can be found in A)
 4. data = (cannot be found in A using exactly one modification)
 5. circl = (cannot be found in A using exactly one modification)
Explanation 2:

 Only pella cannot be found in A using only one modification.


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

    bool search(string& s) {

        Node *a = root;
        return find(a, s, 0, true);
    }

    bool find(Node *a, string &s, int index, bool canChange) {

        if (index == s.length() and canChange == false and a->isEnd) {
            return true;
        }

        if (index == s.length() and canChange == true) {
            return false;
        }

        bool ok = false;
        // without changing
        int k = s[index] - 'a';
        if (a->arr[k] != NULL) {
            ok = ok || find(a->arr[k], s, index + 1, canChange);
            if (canChange) {
                for (int i = 0; i < 26; i++) {
                    if (a->arr[i] and i != k) {
                        ok = ok || find(a->arr[i], s, index + 1, false);
                    }
                }
            }
        }

        if (a->arr[k] == NULL and canChange) {
            for (int i = 0; i < 26; i++) {
                if (a->arr[i] and i != k) {
                    ok = ok || find(a->arr[i], s, index + 1, false);
                }
            }
        }

        return ok;
    }

};

string Solution::solve(vector<string> &a, vector<string> &b) {

    int n = a.size();
    Trie t;
    for (int i = 0; i < n; i++) {
        t.insert(a[i]);
    }

    n = b.size();
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (t.search(b[i])) {
            ans += '1';
        } else {
            ans += '0';
        }
    }

    return ans;
}


