/*
Unique Paths III
Problem Description

Given a matrix of integers A of size N x M . There are 4 types of squares in it:

1. 1 represents the starting square.  There is exactly one starting square.
2. 2 represents the ending square.  There is exactly one ending square.
3. 0 represents empty squares we can walk over.
4. -1 represents obstacles that we cannot walk over.
Find and return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
2 <= N * M <= 20
-1 <= A[i] <= 2



Input Format
The first argument given is the integer matrix A.



Output Format
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Example Input
Input 1:

A = [   [1, 0, 0, 0]
        [0, 0, 0, 0]
        [0, 0, 2, -1]   ]
Input 2:

A = [   [0, 1]
        [2, 0]    ]


Example Output
Output 1:

2
Output 2:

0


Example Explanation
Explanation 1:

We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Explanation 1:

Answer is evident here.

*/
int Solution::solve(vector<vector<int> > &a) {

    int n = a.size();
    int m = a[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                sx = i, sy = j;
            }

            if (a[i][j] == 2) {
                ex = i, ey = j;
            }
        }
    }

    int ans = 0;

    auto ok = [&](int x, int y) {
        if (x >= 0 and x < n and y >= 0 and y < m and visited[x][y] == 0 and a[x][y] != -1) {
            return true;
        }

        return false;
    };

    auto go = [&](int x, int y, const auto & self) {

        visited[x][y] = 1;
        if (a[x][y] == 2) {

            // reached the destination

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (visited[i][j] == 0 and a[i][j] != -1) {
                        visited[x][y] = 0;
                        return;
                    }
                }
            }
            ans++;
            visited[x][y] = 0;
            return;
        }

        if (ok(x, y + 1)) {
            self(x, y + 1, self);
        }

        if (ok(x, y - 1)) {
            self(x, y - 1, self);
        }

        if (ok(x + 1, y)) {
            self(x + 1, y, self);
        }

        if (ok(x - 1, y)) {
            self(x - 1, y, self);
        }


        visited[x][y] = 0;

    };

    go(sx, sy, go);

    return ans;

}


