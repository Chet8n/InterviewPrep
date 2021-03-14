/*
Mod Sum
Problem Description

Given an array of integers A, calculate the sum of A [ i ] % A [ j ] for all possible i, j pairs. Return sum % (109 + 7) as an output.



Problem Constraints
1 <= length of the array A <= 105

1 <= A[i] <= 103



Input Format
The only argument given is the integer array A.



Output Format
Return a single integer denoting sum % (109 + 7).



Example Input
Input 1:

 A = [1, 2, 3]
Input 2:

 A = [17, 100, 11]


Example Output
Output 1:

 5
Output 2:

 61


Example Explanation
Explanation 1:

 (1 % 1) + (1 % 2) + (1 % 3) + (2 % 1) + (2 % 2) + (2 % 3) + (3 % 1) + (3 % 2) + (3 % 3) = 5

*/

int Solution::solve(vector<int> &a) {

    using ll = long long int;
    int n = (int)a.size();
    int mx = -1;

    vector<int> cnt(1e3 + 5, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    ll ans = 0;

    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= mx; j++) {
            ans += (i % j) * cnt[i] * cnt[j];
            ans %= (int)(1e9 + 7);
        }
    }

    return ans;


}

