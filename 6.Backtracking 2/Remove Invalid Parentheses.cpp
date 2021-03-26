/*
Remove Invalid Parentheses
Problem Description

Given a string A consisting of lowercase English alphabets and parentheses '(' and ')'. Remove the minimum number of invalid parentheses in order to make the input string valid.

Return all possible results.

You can return the results in any order.



Problem Constraints
1 <= length of the string <= 20



Input Format
The only argument given is string A.



Output Format
Return all possible strings after removing the minimum number of invalid parentheses.



Example Input
Input 1:

 A = "()())()"
Input 2:

 A = "(a)())()"


Example Output
Output 1:

 ["()()()", "(())()"]
Output 2:

 ["(a)()()", "(a())()"]


Example Explanation
Explanation 1:

 By removing 1 parentheses we can make the string valid.
        1. Remove the parentheses at index 4 then string becomes : "()()()"
        2. Remove the parentheses at index 2 then string becomes : "(())()"
Explanation 2:

 By removing 1 parentheses we can make the string valid.
        1. Remove the parentheses at index 5 then string becomes : "(a)()()"
        2. Remove the parentheses at index 2 then string becomes : "(a())()"
*/


void go(string &a, int left, int right, int index, string &x, vector<string> &ans, int weight) {
    int n = a.length();
    if (index == n) {
        if (left == 0 and right == 0) {
            ans.push_back(x);
        }
        return;
    }

    if (weight < 0) {
        return;
    }

    if (a[index] == '(' and left) {
        go(a, left - 1, right, index + 1, x, ans, weight);
    }

    if (a[index] == ')' and right) {
        go(a, left, right - 1, index + 1, x, ans, weight);
    }

    int toadd = 0;
    if (a[index] == ')') {
        toadd = -1;
    } else if (a[index] == '(') {
        toadd = 1;
    } else {
        toadd = 0;
    }
    x += a[index];
    go(a, left, right, index + 1, x , ans, weight + toadd);
    x.pop_back();
}

vector<string> Solution::solve(string a) {

    int n = a.length();
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '(') {
            left++;
        } else if (a[i] == ')') {
            if (left == 0) {
                right++;
            } else {
                left--;
            }
        }
    }

    vector<string> ans;
    string x;

    go(a, left, right, 0, x, ans, 0);

    sort(ans.begin(), ans.end());

    auto it = unique(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), it));

    return ans;

}

