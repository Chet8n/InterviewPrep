/*
Inversion count in an array
Problem Description

Given an array of integers A. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Find the total number of inversions of A modulo (109 + 7).



Problem Constraints
1 <= length of the array <= 100000

1 <= A[i] <= 10^9



Input Format
The only argument given is the integer array A.



Output Format
Return the number of inversions of A modulo (109 + 7).



Example Input
Input 1:

A = [3, 2, 1]
Input 2:

A = [1, 2, 3]


Example Output
Output 1:

3
Output 2:

0


Example Explanation
Explanation 1:

 All pairs are inversions.
Explanation 2:

 No inversions.


*/
const int mod = 1e9 + 7;
long long int ans = 0;

void merge(vector<int> &a, int l, int m, int r) {

    vector<int> temp(r - l + 5);

    int i = l;
    int j = m + 1;
    int k = 0;
    while (i <= m and j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            ans += (m - i + 1);
            ans %= mod;
        }
    }

    while (i <= m) {
        temp[k++] = a[i++];
    }
    while (j <= r) {
        temp[k++] = a[j++];
    }

    for (i = l, k = 0; i <= r; i++) {
        a[i] = temp[k++];
    }
}

void mergeSort(vector<int> &a, int l, int r) {

    if (l >= r) {
        return;
    }

    int m = (l + r) >> 1;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}


int Solution::solve(vector<int> &a) {

    ans = 0;

    int n = a.size();
    mergeSort(a, 0, n - 1);


    return ans;
}
