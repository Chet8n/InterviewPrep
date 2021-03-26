/*
Number of Squareful Arrays
Problem Description

Given an array of integers A, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Find and return the number of permutations of A that are squareful. Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].



Problem Constraints
1 <= length of the array <= 12

1 <= A[i] <= 109



Input Format
The only argument given is the integer array A.



Output Format
Return the number of permutations of A that are squareful.



Example Input
Input 1:

 A = [2, 2, 2]
Input 2:

 A = [1, 17, 8]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 Only permutation is [2, 2, 2], the sum of adjacent element is 4 and 4 and both are perfect square.
Explanation 2:

 Permutation are [1, 8, 17] and [17, 8, 1].

*/

int Solution::solve(vector<int> &a) {

    int n = a.size();
    vector<bool> taken(n, false);

    if (n == 1) {
        return 0;
    }

    vector<int> x;

    int ans = 0;

    auto go = [&](int prev, int sz, vector<int> &x, const auto & self) {
        if (sz == n) {
            ans++;
            return;
        }

        int last = -1;
        for (int i = 0; i < n; i++) {
            if (!taken[i] and a[i] != last) {
                int sq = sqrt(a[i] + prev);
                if (sq * sq == a[i] + prev) {
                    last = a[i];
                    x.push_back(a[i]);
                    taken[i] = 1;
                    self(a[i], sz + 1, x, self);
                    x.pop_back();
                    taken[i] = 0;

                }
            }
        }
    };

    sort(a.begin(), a.end());

    int last = -1;

    for (int i = 0; i < n; i++) {
        if (last != a[i]) {
            last = a[i];
            x.push_back(a[i]);
            taken[i] = 1;
            go(a[i], 1, x, go);
            x.pop_back();
            taken[i] = 0;
        }
    }

    return ans;

}




