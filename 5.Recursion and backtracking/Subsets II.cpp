/*
Subsets II
Problem Description

Given a collection of integers denoted by array A of size N that might contain duplicates, return all possible subsets.

NOTE:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.


Problem Constraints
0 <= N <= 16



Input Format
Only argument is an integer array A of size N.



Output Format
Return a 2-D vector denoting all the possible subsets.



Example Input
Input 1:

 A = [1, 2, 2]
Input 2:

 A = [1, 1]


Example Output
Output 1:

 [
    [],
    [1],
    [1, 2],
    [1, 2, 2],
    [2],
    [2, 2]
 ]
Output 2:

 [
    [],
    [1],
    [1, 1]
 ]


Example Explanation
Explanation 1:

All the subsets of the array [1, 2, 2] in lexicographically sorted order.
*/

vector<vector<int> > Solution::subsetsWithDup(vector<int> &a) {

    vector<vector<int>> ans;
    int n = a.size();
    vector<int> x;
    
    sort(a.begin(), a.end());

    auto go = [&](int ind, vector<int> &x, const auto & self) {
        ans.push_back(x);
        if (ind == n) {
            return;
        }

        int prev = -1;
        for (int i = ind; i < n; i++) {
            if (i > ind and a[i] == prev) {
                continue;
            }
            prev = a[i];
            x.push_back(a[i]);
            self(i + 1, x, self);
            x.pop_back();
        }
    };

    go(0, x, go);

    return ans;
}



