/*
Permutations
Problem Description

Given an integer array A of size N denoting collection of numbers , return all possible permutations.

NOTE:

No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.


Problem Constraints
1 <= N <= 9



Input Format
Only argument is an integer array A of size N.



Output Format
Return a 2-D array denoting all possible permutation of the array.



Example Input
A = [1, 2, 3]


Example Output
[ [1, 2, 3]
  [1, 3, 2]
  [2, 1, 3] 
  [2, 3, 1] 
  [3, 1, 2] 
  [3, 2, 1] ]


Example Explanation
All the possible permutation of array [1, 2, 3].
*/
vector<vector<int> > Solution::permute(vector<int> &a) {

    int n = (int)a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> ans;

    auto go = [&](int ind, vector<int> x, const auto & self) {

        if (ind == n - 1) {
            ans.push_back(x);
            return;
        }

        char prev = '#';
        for (int i = ind; i < n; i++) {
            if(prev == x[i])
                continue;

            prev = x[i];
            swap(x[i], x[ind]);
            self(ind + 1, x, self);
        }
    };

    vector<int> x;
    x = a;

    go(0, x, go);

    return ans;

}
