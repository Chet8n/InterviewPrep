/*
Palindrome Partitioning
Problem Description

Given a string A, partition A such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of A.

Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR * * *
(len(Entryi[0]) == len(Entryj[0]) AND ... len(Entryi[k] < len(Entryj[k]))


Problem Constraints
1 <= len(A) <= 15



Input Format
First argument is a string A of lowercase characters.



Output Format
Return a list of all possible palindrome partitioning of s.



Example Input
Input 1:

A = "aab"
Input 2:

A = "a"


Example Output
Output 1:

 [
    ["a","a","b"]
    ["aa","b"],
  ]
Output 2:

 [
    ["a"]
  ]


Example Explanation
Explanation 1:

In the given example, ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa").
Explanation 2:

In the given example, only partition possible is "a" .

*/
bool pal(string &s) {

    int n = (int)s.length();
    int i = 0, j = n - 1;
    while(i < j) {
        if (s[i] != s[j]) {
            return false;
        } else {
            i++;
            j--;
        }
    }
    return true;
}

void solve(string &s, vector<string> &x, vector<vector<string>> &ans, int index) {

    int n = (int)s.length();
    if (n == index) {
        ans.push_back(x);
        return;
    }

    for (int len = 1; index + len <= n; len++) {
        string cur = s.substr(index, len);
        if (pal(cur)) {
            x.push_back(cur);
            solve(s, x, ans, index + len);
            x.pop_back();
        }
    }

};

vector<vector<string> > Solution::partition(string A) {

    vector<vector<string>> ans;
    vector<string> x;
    solve(A, x, ans, 0);
    return ans;

}

