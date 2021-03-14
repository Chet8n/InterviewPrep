/*
Min XOR value
Problem Description

Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.



Problem Constraints
2 <= length of the array <= 100000
0 <= A[i] <= 109



Input Format
First and only argument of input contains an integer array A.



Output Format
Return a single integer denoting minimum xor value.



Example Input
Input 1:

 A = [0, 2, 5, 7]
Input 2:

 A = [0, 4, 7, 9]


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

 0 xor 2 = 2


*/
int Solution::findMinXor(vector<int> &a) {

    int n = (int)a.size();
    sort(a.begin(), a.end());
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int here = a[i] ^ a[i + 1];
        ans = min(ans, here);
    }
    return ans;
}

