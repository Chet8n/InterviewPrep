/*
Count Total Set Bits
Problem Description

Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.

Return the count modulo 109 + 7.



Problem Constraints
1 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the ( Total number of set bits in the binary representation of all the numbers from 1 to A )modulo 109 + 7.



Example Input
Input 1:

 A = 3
Input 2:

 A = 1


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 DECIMAL    BINARY  SET BIT COUNT
    1          01        1
    2          10        1
    3          11        2
 1 + 1 + 2 = 4
 Answer = 4 % 1000000007 = 4
Explanation 2:

 A = 1
  DECIMAL    BINARY  SET BIT COUNT
    1          01        1
 Answer = 1 % 1000000007 = 1


*/
int Solution::solve(int a) {

    using ll = long long int;
    int mod = 1e9 + 7;

    auto go = [&](int x, const auto & self) {

        if (x == 0)return 0;

        // find the msb
        int lz = __builtin_clz(x);
        int msb = 32 - lz - 1;
        int ans = 0;
        ans += (1LL * (1 << (msb - 1)) * msb) % mod;
        ans %= mod;
        ans += (x - ((1 << msb) - 1));
        ans %= mod;
        ans += self(x - (1 << msb), self);
        ans %= mod;
        return ans;
    };

    int res = go(a, go);
    return (int)res;


}
