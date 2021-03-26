/*
All Unique Permutations
Problem Description

Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations.

NOTE: No 2 entries in the permutation sequence should be the same.

WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.


Problem Constraints
1 <= |A| <= 9



Input Format
Only argument is an integer array A of size N.



Output Format
Return a 2-D array denoting all possible unique permutation of the array.



Example Input
Input 1:

A = [1, 1, 2]
Input 2:

A = [1, 2]


Example Output
Output 1:

[ [1,1,2]
  [1,2,1]
  [2,1,1] ]
Output 2:

[ [1, 2]
  [2, 1] ]


Example Explanation
Explanation 1:

 All the possible unique permutation of array [1, 1, 2].
Explanation 2:

 All the possible unique permutation of array [1, 2].
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
            if (prev == x[i]) {
                continue;
            }

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
