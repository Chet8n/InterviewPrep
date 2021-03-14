/*
Compute nCr % m
Problem Description

Given three integers A, B and C, where A represents n, B represents r and C represents m, find and return the value of nCr % m where nCr % m = (n!/((n-r)!*r!))% m.

x! means factorial of x i.e. x! = 1 * 2 * 3... * x.



Problem Constraints
1 <= A * B <= 106

1 <= B <= A

1 <= C <= 106



Input Format
The first argument given is integer A ( = n).
The second argument given is integer B ( = r).
The third argument given is integer C ( = m).


Output Format
Return the value of nCr % m.



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

 The value of 5C2 % 11 is 10.
Explanation 2:

 The value of 6C2 % 13 is 2.

*/
int Solution::solve(int n, int r, int mod) {

    // F in the chat coz c(mod) can be any number not necessarily prime
    // so fermats little theorem wont work here

    // lets try pascals triangle
    // just store last row?
    // tht should prolly work

    vector<int> c(r + 1, 0);

    c[0] = 1; // 1C0 = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j >= 1; j--) {
            c[j] = c[j] + c[j - 1];
            c[j] %= mod;
        }
    }

    return c[r];


}

