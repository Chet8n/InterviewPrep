/*
NQueens
Problem Description

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer A, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.



Problem Constraints
1 <= A <= 10



Input Format
First argument is an integer n denoting the size of chessboard



Output Format
Return an array consisting of all distinct solutions in which each element is a 2d char array representing a unique solution.



Example Input
Input 1:

A = 4
Input 2:

A = 1


Example Output
Output 1:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Output 1:

[
 [Q]
]


Example Explanation
Explanation 1:

There exist only two distinct solutions to the 4-queens puzzle:
Explanation 1:

There exist only one distinct solutions to the 1-queens puzzle:


*/
vector<vector<string> > Solution::solveNQueens(int n) {

    vector<int> col(n + 2);
    vector<int> dia1(2 * n + 5);
    vector<int> dia2(2 * n + 5);

    vector<int> config;

    vector<vector<string>> ans;

    auto go = [&](int ind, const auto & self) {

        if (ind == n) {
            // good configuration
            string singlerow;
            for (int i = 0; i < n; i++) {
                singlerow += '.';
            }
            vector<string> here(n, singlerow);
            for (int i = 0; i < n; i++) {
                here[i][config[i]] = 'Q';
            }
            ans.push_back(here);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (col[j] or dia1[ind + j] or dia2[ind + n - j]) {
                continue;
            }

            col[j] = dia1[ind + j] = dia2[ind + n - j] = 1;
            config.push_back(j);
            self(ind + 1, self);
            col[j] = dia1[ind + j] = dia2[ind + n - j] = 0;
            config.pop_back();
        }

    };

    go(0, go);

    return ans;

}


