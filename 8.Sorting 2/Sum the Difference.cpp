/*
Sum the Difference
Problem Description

Given an integer array A of size N.
You have to find all possible non-empty subsequence of the array of numbers and then, for each subsequence, find the difference between the largest and smallest numbers in that subsequence Then add up all the differences to get the number.

As the number may be large, output the number modulo 1e9 + 7 (1000000007).

NOTE: Subsequence can be non-contiguous.



Problem Constraints
1 <= N <= 10000

1<= A[i] <=1000



Input Format
First argument is an integer array A.



Output Format
Return an integer denoting the output.



Example Input
Input 1:

A = [1, 2]
Input 2:

A = [1]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

All possible non-empty subsets are:
[1]    largest-smallest = 1 - 1 = 0
[2]    largest-smallest = 2 - 2 = 0
[1 2]  largest-smallest = 2 - 1 = 1
Sum of the differences = 0 + 0 + 1 = 1
So, the resultant number is 1
Explanation 2:

 Only 1 subsequence of 1 element is formed.

*/

using ll = long long int;
const ll mod = 1e9 + 7;

ll mpow(ll a, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1ll) {
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
        b = b >> 1;
    }
    return ans;
}

int Solution::solve(vector<int> &a) {

    int n = a.size();
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll before = i;
        ll after = n - 1 - i;
        ans += ((mpow(2, before) - 1) * a[i]) % mod;
        ans = ((ans % mod) + mod) % mod;
        ans -= ((mpow(2, after) - 1) * a[i]) % mod;
        ans = ((ans % mod) + mod) % mod;
    }

    return ans;

}
