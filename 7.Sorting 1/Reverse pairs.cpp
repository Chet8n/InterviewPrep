/*
Reverse pairs
Problem Description

Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].
Return the number of important reverse pairs in the given array A.



Problem Constraints
1 <= length of the array <= 100000

1 <= A[i] <= 10^9



Input Format
The only argument given is the integer array A.



Output Format
Return the number of important reverse pairs in the given array A.



Example Input
Input 1:

 A = [1, 3, 2, 3, 1]
Input 2:

 A = [4, 1, 2]


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 There are two pairs which are important reverse i.e (3, 1) and (3, 1).
Explanation 2:

 There is only one pair i.e (4, 1).

*/
const int mod = 1e9 + 7;
long long int ans = 0;

void merge(vector<int> &a, int l, int m, int r) {

    vector<int> temp(r - l + 5);

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m) {
        while (j <= r and a[i] > a[j] * 2) {
            j++;
        }
        ans += j - (m+1);
        i++;
    }

    i = l;
    j = m + 1;

    while (i <= m and j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
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
