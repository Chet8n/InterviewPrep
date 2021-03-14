/*
Single Number III
Problem Description

Given an array of numbers A , in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Note: Output array must be sorted.



Problem Constraints
2 <= |A| <= 100000
1 <= A[i] <= 109



Input Format
First argument is an array of interger of size N.



Output Format
Return an array of two integers that appear only once.



Example Input
Input 1:

A = [1, 2, 3, 1, 2, 4]
Input 2:

A = [1, 2]


Example Output
Output 1:

[3, 4]
Output 2:

[1, 2]


Example Explanation
Explanation 1:

 3 and 4 appear only once.
Explanation 2:

 1 and 2 appear only once.


*/
vector<int> Solution::solve(vector<int> &a) {

    int n = (int)a.size();
    int allxor = 0;
    for (int i = 0; i < n; i++) {
        allxor ^= a[i];
    }

    int setbit = 0;
    for (int i = 0; i < 32; i++) {
        if ((1 << i)& allxor) {
            setbit = (1 << i);
            break;
        }
    }

    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if (setbit & a[i]) {
            num1 ^= a[i];
        } else {
            num2 ^= a[i];
        }
    }

    vector<int> ans;
    if (num1 < num2) {
        ans.push_back(num1);
        ans.push_back(num2);
    } else {
        ans.push_back(num2);
        ans.push_back(num1);
    }
    return ans;

}







