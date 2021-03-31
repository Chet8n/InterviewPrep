/*
Sort stack using another stack
Problem Description

Given a stack of integers A, sort it using another stack.

Return the array of integers after sorting the stack using another stack.



Problem Constraints
1 <= |A| <= 5000

0 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the array of integers after sorting the stack using another stack.



Example Input
Input 1:

 A = [5, 4, 3, 2, 1]
Input 2:

 A = [5, 17, 100, 11]


Example Output
Output 1:

 [1, 2, 3, 4, 5]
Output 2:

 [5, 11, 17, 100]


Example Explanation
Explanation 1:

 Just sort the given numbers.
Explanation 2:

 Just sort the given numbers.

*/
vector<int> Solution::solve(vector<int> &a) {

    int n = a.size();
    stack<int> x, y;
    for (int i = 0; i < n; i++) {
        x.push(a[i]);
    }

    while (!x.empty()) {
        int cur = x.top();
        x.pop();
        while (!y.empty() and y.top() > cur) {
            x.push(y.top());
            y.pop();
        }
        y.push(cur);
    }

    while (!y.empty()) {
        x.push(y.top());
        y.pop();
    }

    vector<int> ans;
    while (!x.empty()) {
        ans.push_back(x.top());
        x.pop();
    }

    return ans;
}

