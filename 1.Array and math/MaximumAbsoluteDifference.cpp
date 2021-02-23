// https://www.interviewbit.com/problems/maximum-absolute-difference/

/*

Case 1: A[i] > A[j] and i > j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = i - j
hence, f(i, j) = (A[i] + i) - (A[j] + j)

Case 2: A[i] < A[j] and i < j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = -(i) + j
hence, f(i, j) = -(A[i] + i) + (A[j] + j)

Case 3: A[i] > A[j] and i < j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = -(i) + j
hence, f(i, j) = (A[i] - i) - (A[j] - j)

Case 4: A[i] < A[j] and i > j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = i - j
hence, f(i, j) = -(A[i] - i) + (A[j] - j)

*/

const int inf = 1e9;

int Solution::maxArr(vector<int> &a) {
    
    int max1 = -inf;
    int max2 = -inf;
    int min1 = inf;
    int min2 = inf;
    
    int n = (int)a.size();
    
    for(int i = 0;i < n;i++){
        max1 = max(max1, a[i] + i);
        min1 = min(min1, a[i] + i);
        max2 = max(max2, a[i] - i);
        min2 = min(min2, a[i] - i);
    }
    
    int ans = max(max1 - min1, max2 - min2);
    return ans;
     
}
