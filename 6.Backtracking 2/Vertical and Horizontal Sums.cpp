/*
Vertical and Horizontal Sums
Problem Description

Given a matrix B, of size N x M, you are allowed to do at most A special operations on this grid such that there is no vertical or horizontal contiguous subarray that has a sum greater than C.

A special operation involves multiplying any element by -1 i.e. changing its sign.

Return 1 if it is possible to achieve the answer, otherwise 0.



Problem Constraints
1 <= N, M <= 10

0 <= A <= 5

-105 <= B[i][j], C <= 105



Input Format
The first argument is an integer A, representing the number of special operations allowed.
The second argument has the N x M integer matrix, B.
The third argument is an integer C, as described in the problem statement.



Output Format
Return 1 if it is possible to achieve the answer, otherwise 0.



Example Input
Input 1:

 A = 3
 B = [
        [1, 1, 1]
        [1, 1, 1]
        [1, 1, 1]
     ]
 C = 2
Input 2:

 A = 1
 B = [
        [1, 1, 1]
        [1, 1, 1]
        [1, 1, 1]
     ]
 C = 2


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 The given matrix does not satisfy the conditions, but if we apply the special operation to B[0][0], B[1][1], B[2][2],
 then the matrix would satisfy the given conditions i.e. no row or column has a sum greater than 2.
Explanation 2:

 It is not possible to apply the special operation to 1 element to satisfy the conditions.

*/

bool ok(vector<vector<int>> &b, int c) {
    int n = b.size();
    int m = b[0].size();
    for (int i = 0; i < n; i++) {
        int msf = -1e8;
        int sum = -1e8;
        for (int j = 0; j < m; j++) {
            msf = max(msf + b[i][j], b[i][j]);
            sum = max(sum, msf);
        }
        if (sum > c) {
            return false;
        }
    }

    for (int j = 0; j < m; j++) {
        int msf = -1e8;
        int sum = -1e8;
        for (int i = 0; i < n; i++) {
            msf = max(msf + b[i][j], b[i][j]);
            sum = max(sum, msf);
        }
        if (sum > c) {
            return false;
        }
    }

    return true;
}

bool go(int a, vector<vector<int>> &b, int c, int x, int y) {
    int n = b.size();
    int m = b[0].size();

    if (ok(b, c)) {
        return true;
    }
    if (a == 0 or x == n) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ( (i == x and j >= y) or (i > x)) {
                if (b[i][j] > 0) {
                    b[i][j] = -b[i][j];
                    if (j == m - 1) {
                        if (go(a - 1, b, c, i + 1, 0)) {
                            return true;
                        }
                    } else {
                        if (go(a - 1, b, c, i, j + 1)) {
                            return true;
                        }
                    }
                    b[i][j] = -b[i][j];
                }
            }
        }
    }

    return false;
}



int Solution::solve(int a, vector<vector<int> > &b, int c) {

    bool ans = go(a, b, c, 0, 0);

    return ans ? 1 : 0;

}

