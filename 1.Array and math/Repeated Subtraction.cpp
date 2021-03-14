/*
Repeated Subtraction
You are given 2 numbers P and Q.

An operation on these 2 numbers is defined as follows: Take the smaller number of the 2 numbers and subtract it from the bigger number. Keep performing this operation till either of the following criterion is met:

Both numbers become equal.
Either of the number becomes 0.
Find the sum of the final values of P and Q.

Constraints:

 0 <= P,Q <= 1e9
Input:

Two integers P and Q
Output:

Sum of the final values of P and Q
Example:

Input:

P : 5 
Q : 15
Output:

10
Explanation:

For the first operation, smaller of P and Q is P.
So we subtract P from Q which gives us the new values of P and Q as 5 and 10 resp.
For the second operation, smaller of P and Q is P.
So we subtract P from Q which gives us the new values of P and Q as 5 and 5 resp.
Since the values of P and Q are now same, we output the sum of these values=10.


 */

int Solution::getFinal(int a, int b) {
    
    if(a == 0 or b == 0){
        return a+b;
    }
        
    int g = __gcd(a, b);
    return 2*g;
    
}


