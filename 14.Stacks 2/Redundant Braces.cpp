/*
Redundant Braces
Problem Description

Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.



Problem Constraints
1 <= |A| <= 105



Input Format
The only argument given is string A.



Output Format
Return 1 if A has redundant braces, else return 0.



Example Input
Input 1:

 A = "((a+b))"
Input 2:

 A = "(a+(a+b))"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 ((a+b)) has redundant braces so answer will be 1.
Explanation 2:

 (a+(a+b)) doesn't have have any redundant braces so answer will be 0.

*/
int Solution::braces(string a) {

    int n = a.size();
    stack<char> s;
    for (int i = 0; i < n; i++) {
        if (a[i] == '(' ) {
            s.push(a[i]);
        } else if (a[i] == '+' or a[i] == '-' or a[i] == '*' or a[i] == '/') {
            s.push(a[i]);
        } else if (a[i] == ')') {
            char x = s.top();
            s.pop();
            if (x == '(') {
                return 1;
            } else {
                s.pop();
            }
        }
    }

    return 0;
}
