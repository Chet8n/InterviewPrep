/*
Points on same line
Problem Description

Given two array of integers A and B describing a pair of (A[i], B[i]) coordinates in 2D plane. A[i] describe x coordinates of the ith point in 2D plane whereas B[i] describes the y-coordinate of the ith point in 2D plane.

Find and return the maximum number of points which lie on the same line.



Problem Constraints
1 <= (length of the array A = length of array B) <= 1000

-105 <= A[i], B[i] <= 105



Input Format
First argument is an integer array A.
Second argument is an integer array B.



Output Format
Return the maximum number of points which lie on the same line.



Example Input
Input 1:

 A = [-1, 0, 1, 2, 3, 3]
 B = [1, 0, 1, 2, 3, 4]
Input 2:

 A = [3, 1, 4, 5, 7, -9, -8, 6]
 B = [4, -8, -3, -2, -1, 5, 7, -4]


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 The maximum number of point which lie on same line are 4, those points are {0, 0}, {1, 1}, {2, 2}, {3, 3}.
Explanation 2:

 Any 2 points lie on a same line.


*/
int Solution::solve(vector<int> &a, vector<int> &b) {

    /**

    - slope of 2 points = (y2- y1)/(x2 - x1);

    **/

    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, int> m;
        int same = 1;
        int here = 0;
        int vertical = 0;
        int horizontal = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j] and b[i] == b[j]) {
                same++;
                continue;
            }

            int dx = a[i] - a[j];
            int dy = b[i] - b[j];

            if (dx == 0) {
                vertical++;
                continue;
            }

            if (dy == 0) {
                horizontal++;
                continue;
            }

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }

            int g = __gcd(abs(dx), abs(dy));

            m[ {dx / g, dy / g}]++;
            here = max(here, m[ {dx / g, dy / g}]);
        }

        here += same ;
        ans = max(ans, here);
        ans = max(ans, same + horizontal);
        ans = max(ans, same + vertical);
    }

    return ans;

}

