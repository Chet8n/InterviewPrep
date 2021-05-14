/*

Make String Pallindrome
Problem Description

Given a string A of size N consisting only of lowercase alphabets. The only operation allowed is to insert characters in the beginning of the string.

Find and return how many minimum characters are needed to be inserted to make the string a palindrome string.



Problem Constraints
1 <= N <= 106



Input Format
The only argument given is a string A.



Output Format
Return an integer denoting the minimum characters that are needed to be inserted to make the string a palindrome string.



Example Input
Input 1:

 A = "abc"
Input 2:

 A = "bb"


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

 Insert 'b' at beginning, string becomes: "babc".
 Insert 'c' at beginning, string becomes: "cbabc".
Explanation 2:

 There is no need to insert any character at the beginning as the string is already a palindrome. 

*/

vector<int> prefix_function(string &s) {

    int n = s.length();
    vector<int> lps(n);

    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 and s[j] != s[i]) {
            j = lps[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
    }

    return lps;
}

int Solution::solve(string a) {

    int n = a.length();
    string s = a + '#';
    reverse(a.begin(), a.end());
    s += a;
    vector<int> lps = prefix_function(s);

    return n - lps.back();



}
