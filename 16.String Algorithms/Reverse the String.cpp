/*

Reverse the String
Problem Description

Given a string A of size N.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.


Problem Constraints
1 <= N <= 3 * 105



Input Format
The only argument given is string A.



Output Format
Return the string A after reversing the string word by word.



Example Input
Input 1:
    A = "the sky is blue"
Input 2:
    A = "this is ib"


Example Output
Output 1:
    "blue is sky the"
Output 2:
    "ib is this"


Example Explanation
Explanation 1:
    We reverse the string word by word so the string becomes "the sky is blue".
Explanation 2:
    We reverse the string word by word so the string becomes "this is ib".


*/

string Solution::solve(string s) {

	int n = s.length();
	int i = 0;
	int j = 0;
	while (i < n and j < n) {

		while (i < n and s[i] == ' ') {
			i++;
		}
		j = i;

		while (j < n and s[j] != ' ') {
			j++;
		}

		reverse(s.begin() + i, s.begin() + j);
		i = j + 1;
		j = i;
	}

	reverse(s.begin(), s.end());

	i = 0;
	j = n - 1;
	while (s[i] == ' ' and i < n) {
		i++;
	}

	while (j >= 0 and s[j] == ' ') {
		j--;
	}

	string ans = "";
	for (int k = i; k <= j; k++) {
		if (k != i and ans.back() == ' ' and s[k] == ' ') {
			continue;
		}
		ans += s[k];
	}

	return ans;

}