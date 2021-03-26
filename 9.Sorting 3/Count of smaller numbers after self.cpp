/*
Count of smaller numbers after self
Problem Description

Given an array of integers A, find and return new integer array B.

Array B has the property where B[i] is the number of smaller elements to the right of A[i].



Problem Constraints
1 <= length of the array <= 100000

1 <= A[i] <= 109



Input Format
The only argument given is the integer array A.



Output Format
Return the new integer array B.



Example Input
A = [1, 5, 4, 2, 1]


Example Output
[0, 3, 2, 1, 0]


Example Explanation
Number of smaller elements to the right of 1 are 0.
Number of smaller elements to the right of 5 are 3 (4, 2, 1).
Number of smaller elements to the right of 4 are 2 (2, 1).
Number of smaller elements to the right of 2 are 1 (1).
Number of smaller elements to the right of 1 are 0.

*/
using pi = pair<int, int>;

vector<int> ans;

void merge(vector<pi> &a, int s, int m, int e) {
    vector<pi> temp(e - s + 1);

    int i = s;
    int j = m + 1;
    int k = 0;
    while (i <= m and j <= e) {
        if (a[i].first <= a[j].first) {
            ans[a[i].second] += j - (m + 1);
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= m) {
        ans[a[i].second] += j - (m + 1);
        temp[k++] = a[i++];
    }

    while (j <= e) {
        temp[k++] = a[j++];
    }

    for (i = s, k = 0; i <= e; i++, k++) {
        a[i] = temp[k];
    }
}

void mergeSort(vector<pi> &a, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = ( s + e) >> 1;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, mid, e);
}


vector<int> Solution::solve(vector<int> &a) {

    int n = a.size();
    ans = vector<int>(n, 0);
    vector<pi> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = {a[i], i};
    }

    mergeSort(b, 0, n - 1);

    return ans;

}
