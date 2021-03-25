/*
Maximum height of staircase
Problem Description

Given an integer A representing the number of square blocks. The height of each square block is 1. The task is to create a staircase of max height using these blocks.

The first stair would require only one block, the second stair would require two blocks and so on.

Find and return the maximum height of the staircase.



Problem Constraints
0 <= A <= 109


Input Format
The only argument given is integer A.



Output Format
Return the maximum height of the staircase using these blocks.



Example Input
Input 1:

 A = 10
Input 2:

 20


Example Output
Output 1:

 4
Output 2:

 5

*/

int Solution::solve(int A) {

    using ll = long long int;
    ll a = A;
    ll s = 0;
    ll e = 1e6;
    ll ans = 0;
    auto get = [&](ll x) {
        ll res = x * (x + 1) / 2;
        return res;
    };

    while (s <= e) {
        ll mid = (s + e) >> 1;
        if (get(mid) <= a) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;


}





