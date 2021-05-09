/*

Infix to Postfix
Problem Description

Given string A denoting an infix expression. Convert the infix expression into postfix expression.

String A consists of ^, /, *, +, -, (, ) and lowercase english alphabets where lowercase english alphabets are operands and ^, /, *, +, - are operators.

Find and return the postfix expression of A.

NOTE:

^ has highest precedence.
/ and * have equal precedence but greater than + and -.
+ and - have equal precedence and lowest precedence among given operators.


Problem Constraints
1 <= length of the string <= 500000



Input Format
The only argument given is string A.



Output Format
Return a string denoting the postfix conversion of A.



Example Input
Input 1:

 A = "x^y/(a*z)+b"
Input 2:

 A = "a+b*(c^d-e)^(f+g*h)-i"


Example Output
Output 1:

  "xy^az*_b+" add / at underscore
Output 2:

 "abcd^e-fgh*+^*+i-"


Example Explanation
Explanation 1:

 Ouput dentotes the postfix expression of the given input.

*/

string Solution::solve(string a) {

	int n = a.length();

	stack<char> s;
	string postfix = "";

	auto getPrecedence = [&](char c) -> int{
		if (c == '^')return 3;
		else if (c == '*' or c == '/')return 2;
		else if (c == '+' or c == '-') return 1;
		else return -1;
	};


	for (int i = 0; i < n; i++) {
		if (a[i] >= 'a' and a[i] <= 'z') {
			postfix += a[i];
		} else if (a[i] == '(') {
			s.push(a[i]);
		} else if (a[i] == ')') {
			while (s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();
		} else {
			while (!s.empty() and getPrecedence(s.top()) >= getPrecedence(a[i])) {
				postfix += s.top();
				s.pop();
			}
			s.push(a[i]);
		}
	}

	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	return postfix;
}
