/*
Count Right Triangles
Problem Description

Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) for 0 <= i < N represents a unique point (x, y) in 2D Cartesian plane.

Find and return the number of unordered triplets (i, j, k) such that (A[i], B[i]), (A[j], B[j]) and (A[k], B[k]) form a right angled triangle with the triangle having one side parallel to the x-axis and one side parallel to the y-axis.

NOTE: The answer may be large so return the answer modulo (109 + 7).



Problem Constraints
1 <= N <= 105

0 <= A[i], B[i] <= 109



Input Format
The first argument given is an integer array A.
The second argument given is the integer array B.



Output Format
Return the number of unordered triplets that form a right angled triangle modulo (109 + 7).



Example Input
Input 1:

 A = [1, 1, 2]
 B = [1, 2, 1]
Input 2:

 A = [1, 1, 2, 3, 3]
 B = [1, 2, 1, 2, 1]


Example Output
Output 1:

 1
Output 2:

 6


Example Explanation
Explanation 1:

 All three points make a right angled triangle. So return 1.
Explanation 2:

 6 quadruplets which make a right angled triangle are: (1, 1), (1, 2), (2, 2)
                                                       (1, 1), (3, 1), (1, 2)
                                                       (1, 1), (3, 1), (3, 2)
                                                       (2, 1), (3, 1), (3, 2)
                                                       (1, 1), (1, 2), (3, 2)
                                                       (1, 2), (3, 1), (3, 2)

*/
int Solution::solve(vector<int> &a, vector<int> &b) {

    using ll = long long int;
    ll mod = 1e9 + 7;
    int n = a.size();

    map<int, int> mx, my;
    for (int i = 0; i < n; i++) {
        mx[a[i]]++;
        my[b[i]]++;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += ((mx[a[i]] - 1) * (my[b[i]] - 1)) % mod;
        ans %= mod;
    }

    return (int)ans;

}

