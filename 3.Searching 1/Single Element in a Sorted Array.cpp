/*
Single Element in a Sorted Array
Problem Description

Given a sorted array of integers A where every element appears twice except for one element which appears once, find and return this single element that appears only once.

NOTE: Users are expected to solve this in O(log(N)) time.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10^9



Input Format
The only argument given is the integer array A.



Output Format
Return the single element that appears only once.



Example Input
Input 1:

A = [1, 1, 7]
Input 2:

A = [2, 3, 3]


Example Output
Output 1:

 7
Output 2:

 2


Example Explanation
Explanation 1:

 7 appears once
Explanation 2:

 2 appears once
*/

int Solution::solve(vector<int> &a) {

    int n = (int)a.size();
    if (n == 1)return a[0];

    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = (s + e) >> 1;
        if (mid & 1) {
            if (a[mid] == a[mid - 1]) {
                s = mid + 1;
            } else if (mid != n - 1 and a[mid] == a[mid + 1]) {
                e = mid - 1;
            } else {
                ans = mid;
                break;
            }
        } else {
            if (a[mid] == a[mid + 1]) {
                s = mid + 1;
            } else if (mid != 0 and a[mid] == a[mid - 1]) {
                e = mid - 1;
            } else {
                ans = mid;
                break;
            }
        }
    }

    return a[ans];
}


