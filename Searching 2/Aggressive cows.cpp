/*
Aggressive cows
Problem Description

Farmer John has built a new long barn, with N stalls. Given an array of integers A of size N where each element of the array represents the location of the stall, and an integer B which represent the number of cows.

His cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, John wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?



Problem Constraints
2 <= N <= 100000
0 <= A[i] <= 109
2 <= B <= N



Input Format
The first argument given is the integer array A.
The second argument given is the integer B.



Output Format
Return the largest minimum distance possible among the cows.



Example Input
Input 1:

A = [1, 2, 3, 4, 5]
B = 3
Input 2:

A = [1, 2]
B = 2


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:


John can assign the stalls at location 1,3 and 5 to the 3 cows respectively.
So the minimum distance will be 2.
Explanation 2:


The minimum distance will be 1.

*/
int Solution::solve(vector<int> &a, int b) {

    using ll = long long int;
    /**

    - search space for gap between the cows is [0 (a[n-1] - a[0])]
    - binary search on this space and pick the maximum gap possible

    **/

    sort(a.begin(), a.end());

    int n = (int)a.size();

    auto ok = [&](ll x) {
        ll cows = 1;
        ll prev = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] - prev >= x) {
                cows++;
                prev = a[i];
            }
        }

        return (cows >= b);
    };

    ll s = 0;
    ll e = 1e10;
    ll ans = 0;
    while (s <= e) {
        ll mid = (s + e) >> 1;
        if (ok(mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;
}

