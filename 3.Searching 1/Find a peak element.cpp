/*
Find a peak element
Problem Description

Given an array of integers A, find and return the peak element in it. An array element is peak if it is NOT smaller than its neighbors.

For corner elements, we need to consider only one neighbor. We ensure that answer will be unique.

NOTE: Users are expected to solve this in O(log(N)) time.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 109



Input Format
The only argument given is the integer array A.



Output Format
Return the peak element.



Example Input
Input 1:

A = [1, 2, 3, 4, 5]
Input 2:

A = [5, 17, 100, 11]


Example Output
Output 1:

 5
Output 2:

 100


Example Explanation
Explanation 1:

 5 is the peak.
Explanation 2:

 100 is the peak.
*/

int Solution::solve(vector<int> &a) {

    int n = (int)a.size();

    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = (s + e) >> 1;
        if (mid == 0 and mid == n - 1) {
            ans = mid;
            break;
        } else {
            if (a[mid] >= a[mid - 1] and a[mid] >= a[mid + 1]) {
                ans = mid;
                break;
            } else if (a[mid] >= a[mid - 1]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }

    return a[ans];
}



