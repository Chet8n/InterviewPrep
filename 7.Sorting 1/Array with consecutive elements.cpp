/*
Array with consecutive elements
Problem Description

Given an array of positive integers A, check and return whether the array elements are consecutive or not.
NOTE: Try this with O(1) extra space.



Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9



Input Format
The only argument given is the integer array A.



Output Format
Return 1 if the array elements are consecutive else return 0.



Example Input
Input 1:

 A = [3, 2, 1, 4, 5]
Input 2:

 A = [1, 3, 2, 5]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 As you can see all the elements are consecutive, so we return 1.
Explanation 2:

 Element 4 is missing, so we return 0.

*/
int Solution::solve(vector<int> &a) {

    int n = a.size();

    int mn = *min_element(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        a[i] -= mn;
    }

    for (int i = 0; i < n; i++) {
        while (a[i] > 0 and a[i] < n and a[i] != a[a[i]]) {
            swap(a[i], a[a[i]]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != a[i]) {
            return false;
        }
    }

    return true;
}
