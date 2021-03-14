/*
Very Large Power
Problem Description

Given two Integers A, B. You have to calculate (A ^ (B!)) % (1e9 + 7).

"^" means power ,

"%" means "mod", and

"!" means factorial.



Problem Constraints
1 <= A, B <= 5e5



Input Format
First argument is the integer A

Second argument is the integer B



Output Format
Return one integer, the answer to the problem



Example Input
Input 1:

A = 1
B = 1
Input 2:

A = 2
B = 2


Example Output
Output 1:

1
Output 2:

4


Example Explanation
Explanation 1:

 1! = 1. Hence 1^1 = 1.
Explanation 2:

 2! = 2. Hence 2^2 = 4.

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

int Solution::solve(int a, int b) {


    // (A ^ (B!)) % (1e9 + 7).
    ll p = 1;
    for (int i = 1; i <= b; i++) {
        p *= i;
        p %= (mod - 1);
    }

    ll ans = mpow(a, p);
    return ans;


}


