/*
Ath Magical Number
Problem Description

Given three positive integers A, B and C.

Any positive integer is magical if it is divisible by either B or C.

Return the Ath magical number. Since the answer may be very large, return it modulo 109 + 7.



Problem Constraints
1 <= A <= 109

2 <= B, C <= 40000



Input Format
The first argument given is an integer A.

The second argument given is an integer B.

The third argument given is an integer C.



Output Format
Return the Ath magical number. Since the answer may be very large, return it modulo 109 + 7.



Example Input
Input 1:

 A = 1
 B = 2
 C = 3
Input 2:

 A = 4
 B = 2
 C = 3


Example Output
Output 1:

 2
Output 2:

 6


Example Explanation
Explanation 1:

 1st magical number is 2.
Explanation 2:

 First four magical numbers are 2, 3, 4, 6 so the 4th magical number is 6.

*/
int Solution::solve(int a, int b, int c) {

    using ll = long long int;

    auto ok = [&](ll x) {
        ll frst = x / b;
        ll sec = x / c;
        ll lcm = (b * c) / (__gcd(b, c));
        ll intersection = x / lcm;
        ll uni = frst + sec - intersection;

        return (uni >= a);
    };

    ll s = 1;
    ll e = 1e18;
    ll ans = 1;
    while (s <= e) {
        ll mid = (s + e) >> 1;
        if (ok(mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    int mod = 1e9 + 7;

    return ans % (mod);
}
