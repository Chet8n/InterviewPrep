/*
Compute nCr % p
Problem Description

Given three integers A, B and C, where A represents n, B represents r and C represents p and p is a prime number greater than equal to n, find and return the value of nCr % p where nCr % p = (n! / ((n-r)! * r!)) % p.

x! means factorial of x i.e. x! = 1 * 2 * 3... * x.

NOTE: For this problem, we are considering 1 as a prime.



Problem Constraints
1 <= A <= 106
1 <= B <= A
A <= C <= 109+7


Input Format
The first argument given is the integer A ( = n).
The second argument given is the integer B ( = r).
The third argument given is the integer C ( = p).



Output Format
Return the value of nCr % p.



Example Input
Input 1:

 A = 5
 B = 2
 C = 13
Input 2:

 A = 6
 B = 2
 C = 13


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

 nCr( n=5 and r=2) = 10.
 p=13. Therefore, nCr%p = 10.

*/

using ll = long long int;
int N;
ll mod;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

vector<ll> fact;
void pre() {
    fact = vector<ll>(N + 5, 0);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = i * fact[i - 1] % mod;
}

ll C(int n, int k) {
    if (k < 0 || k > n)return 0;
    ll num = fact[n];
    ll dem = fact[k] * fact[n - k] % mod;
    return num * modinv(dem) % mod;
}

int Solution::solve(int n, int r, int p) {

    mod = p;
    N = n;
    pre();
    ll ans = C(n, r);

    return ans;

}





