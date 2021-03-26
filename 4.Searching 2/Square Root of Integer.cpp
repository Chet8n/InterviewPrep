/*
Square Root of Integer
Problem Description

Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.

NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.



Problem Constraints
0 <= A <= 1010



Input Format
The first and only argument given is the integer A.



Output Format
Return floor(sqrt(A))



Example Input
Input 1:

 11
Input 2:

 9


Example Output
Output 1:

 3
Output 2:

 3


Example Explanation
Explanation:

 When A = 11 , square root of A = 3.316. It is not a perfect square so we return the floor which is 3.
 When A = 9 which is a perfect square of 3, so we return 3.

*/
int Solution::sqrt(int a) {

    using ll = long long int;
    ll s = 0;
    ll e = 1e6;
    ll ans;
    while (s <= e) {
        ll mid = (s + e) >> 1;
        if (mid * mid <= a) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}
