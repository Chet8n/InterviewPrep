/*
Pairs with given sum II
Problem Description

Given a sorted array of integers (not necessarily distinct) A and an integer B, find and return how many pair of integers ( A[i], A[j] ) such that i != j have sum equal to B.

Since the number of such pairs can be very large, return number of such pairs modulo (109 + 7).



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10^9

1 <= B <= 10^9



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the number of pairs for which sum is equal to B modulo (10^9+7).



Example Input
Input 1:

A = [1, 1, 1]
B = 2
Input 2:

 
A = [1, 1]
B = 2


Example Output
Output 1:

 3
Output 2:

 1


Example Explanation
Explanation 1:

 Any two pairs sum up to 2.
Explanation 2:

 only pair (1, 2) sums up to 2.

*/
int Solution::solve(vector<int> &a, int b) {

    using ll = long long int;
    int n = a.size();
    ll mod = 1e9 + 7;
    ll ans = 0;
    int i = 0;
    int j = n - 1;
    while (i < j) {
        ll sum = a[i] + a[j];
        if (sum == b) {
            if (a[i] != a[j]) {
                ll cnta = 1;
                ll cntb = 1;
                while (i + 1 < j and a[i] == a[i + 1]) {
                    i++;
                    cnta++;
                }
                while (j > i + 1 and a[j] == a[j - 1]) {
                    j--;
                    cntb++;
                }

                ans += (cnta * cntb) % mod;
                ans %= mod;
                i++;
                j--;
            } else {
                ll cnt = (j-i+1);
                ans += (cnt * (cnt - 1)) / 2;
                ans %= mod;
                break;
            }
        } else if (sum > b) {
            j--;
        } else {
            i++;
        }
    }

    return ans;

}
