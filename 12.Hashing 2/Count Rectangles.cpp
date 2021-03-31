/*
Count Rectangles
Problem Description

Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) for 0 <= i < N represents a unique point (x, y) in 2-D Cartesian plane.

Find and return the number of unordered quadruplet (i, j, k, l) such that (A[i], B[i]), (A[j], B[j]), (A[k], B[k]) and (A[l], B[l]) form a rectangle with the rectangle having all the sides parallel to either x-axis or y-axis.



Problem Constraints
1 <= N <= 2000
0 <= A[i], B[i] <= 109



Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.



Output Format
Return the number of unordered quadruplet that form a rectangle.



Example Input
Input 1:

 A = [1, 1, 2, 2]
 B = [1, 2, 1, 2]
Input 1:

 A = [1, 1, 2, 2, 3, 3]
 B = [1, 2, 1, 2, 1, 2]


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

 All four given points make a rectangle. So, the answer is 1.
Explanation 2:

 3 quadruplets which make a rectangle are: (1, 1), (2, 1), (2, 2), (1, 2)
                                           (1, 1), (3, 1), (3, 2), (1, 2)
                                           (2, 1), (3, 1), (3, 2), (2, 2)

*/
int Solution::solve(vector<int> &a, vector<int> &b) {

    int n = a.size();
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++) {
        m[ {a[i], b[i]}]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] > a[i] and b[j] > b[i]) {
                ans += (m[ {a[i], b[j]}] != 0 and m[ {a[j], b[i]}] != 0);
            }
        }
    }

    return ans;
}

