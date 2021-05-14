/*

Smallest Prefix String
Problem Description

Given 2 strings A and B of size N and M respectively consisting of lowercase alphabets, find the lexicographically smallest string that can be formed by concatenating non empty prefixes of A and B (in that order).
Note: The answer string has to start with a non empty prefix of string A followed by a non empty prefix of string B.



Problem Constraints
1 <= N, M <= 100000



Input Format
First argument is a string A of size N.
Second argument is a string B of size M.



Output Format
Return a string denoting Lexicographically smallest string that can be formed by concatenating non empty prefixes of A and B (in that order).



Example Input
Input 1:

 A = "abba"
 B = "cdd"
Input 2:

 A = "acd"
 B = "bay"


Example Output
Output 1:

 "abbac"
Output 2:

 "ab"


Example Explanation
Explanation 1:

 We can concatenate prefix of A i.e "abba" and prefix of B i.e "c".
 The lexicographically smallest string will be "abbac".
Explanation 2:

 We can concatenate prefix of A i.e "a" and prefix of B i.e "b".
 The lexicographically smallest string will be "ab".

*/

string Solution::smallestPrefix(string a, string b) {

    string ans = "";
    int na = a.length();
    int nb = b.length();
    ans += a[0];
    for (int i = 1; i < na; i++) {
        if (a[i] < b[0]) {
            ans += a[i];
        } else {
            break;
        }
    }
    ans += b[0];
    return ans;
}
