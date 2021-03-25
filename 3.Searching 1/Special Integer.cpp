/*
Special Integer
Problem Description

Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with sum of elements greater than B.



Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 10^9

1 <= B <= 10^9



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the maximum value of K (sub array length).



Example Input
Input 1:

A = [1, 2, 3, 4, 5]
B = 10
Input 2:

A = [5, 17, 100, 11]
B = 130


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

Constraints are satisfied for maximal value of 2.
Explanation 2:

Constraints are satisfied for maximal value of 3.

*/

int Solution::solve(vector<int> &a, int b) {

    int n = (int)a.size();
    int j = 0;
    long long int sum = 0;
    int ans = 1e9;
    for (int i = 0; i < n and j < n; i++) {
        while (j < n) {
            if (sum + a[j] <= b) {
                sum += a[j];
                j++;
            } else {
                break;
            }
        }
        int here = j - i;
        ans = min(ans, here);
        sum -= a[i];
    }

    return ans;
}
