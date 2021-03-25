/*
Sorted Insert Position
Problem Description

Given a sorted array A of size N and a target value B, return the index (0-based indexing) if the target is found.
If not, return the index where it would be if it were inserted in order.

NOTE: You may assume no duplicates in the array. Users are expected to solve this in O(log(N)) time.



Problem Constraints
1 <= N <= 106



Input Format
First argument is an integer array A of size N.
Second argument is an integer B.



Output Format
Return an integer denoting the index of target value.



Example Input
Input 1:

A = [1, 3, 5, 6]
 B = 5
Input 2:

A = [1]
 B = 1


Example Output
Output 1:

2
Output 2:

0


Example Explanation
Explanation 1:

The target value is present at index 2.
Explanation 2:

The target value is present at index 0.

*/

int Solution::searchInsert(vector<int> &a, int b) {
    int n = (int)a.size();

    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = (s + e) >> 1;
        if (a[mid] < b) {
            ans = mid + 1;
            s = mid + 1;
        } else {
            ans = mid;
            e = mid - 1;
        }
    }

    return ans;
}

