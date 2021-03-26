/*
Smallest Good Base
Given an integer A, we call k >= 2 a good base of A, if all digits of A base k are 1. Now given a string representing A, you should return the smallest good base of A in string format.


Input Format

The only argument given is the string representing A.
Output Format

Return the smallest good base of A in string format.
Constraints

3 <= A <= 10^18
For Example

Input 1:
    A = "13"
Output 1:
    "3"     (13 in base 3 is 111)

Input 2:
    A = "4681"
Output 2:
    "8"     (4681 in base 8 is 11111).

*/
string Solution::solve(string A) {

    using ll = long long int;
    ll a = stoll(A);
    /**

    - a-1 is always a answer bcoz a-1^1 + a-1^0 = a;
    - n = 1 + k^1 + k^2 + k^3 + . . . . . k^m-1 --> m 1's in base k representation
    - the above form a GP
    - sum of GP = a1(1 - r^m)/(1 - r) = 1 (1 - k^m)/(1 - k)
    - we know thar m can only be from 1 to 63
    - iterate over m from 63 to 1 and binary search k from range 2 to pow(n, 1/m)
    - This should prolly work
    - to avoid overflow lets just start m from log2(a)

    **/

    for (int m = log(a + 1) / log(2); m >= 2; m--) {
        // BS k here
        ll s = 2;
        ll e = pow(a, 1.0 / (m - 1)) + 1;
        while (s <= e) {
            ll mid = (s + e) >> 1;
            ll here = 0;
            for (int i = 0; i < m; i++) {
                here = here * mid + 1;
            }

            if (here == a) {
                return to_string(mid);
            }

            if (here < a) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }

    return to_string(a - 1);


}
