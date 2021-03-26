/*
Maximum Unsorted Subarray
Problem Description

Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar such that if we sort(in ascending order) that sub-array, then the whole array should get sorted. If A is already sorted, output -1.



Problem Constraints
1 <= N <= 1000000
1 <= A[i] <= 1000000



Input Format
First and only argument is an array of non-negative integers of size N.



Output Format
Return an array of length 2 where First element denotes the starting index(0-based) and second element denotes the ending index(0-based) of the sub-array. If the array is already sorted, return an array containing only one element i.e. -1.



Example Input
Input 1:

A = [1, 3, 2, 4, 5]
Input 2:

A = [1, 2, 3, 4, 5]


Example Output
Output 1:

[1, 2]
Output 2:

[-1]


Example Explanation
Explanation 1:

If we sort the sub-array A1, A2, then the whole array A gets sorted.
Explanation 2:

A is already sorted.

*/

/*
TC : o(N log N)
SC : o(N)
vector<int> Solution::subUnsort(vector<int> &a) {
    
    vector<int> b = a;
    sort(b.begin(), b.end());
    
    int n = a.size();
    
    int s = -1;
    int e = -1;
    
    for(int i = 0;i < n ;i++){
        if(a[i] != b[i] ){
            s = i;
            break;
        }
    }
    
    vector<int> ans;
    
    if(s == -1){
        ans.push_back(-1);
        return ans;
    }
    
    for(int i = n-1;i >= 0;i--){
        if(a[i] != b[i]){
            e = i;
            break;
        }
    }
    ans.push_back(s);
    ans.push_back(e);
    
    return ans;
}

*/

// TC : o(N) and SC = o(1)

vector<int> Solution::subUnsort(vector<int> &a) {

    int n = a.size();
    int s = -1, e = -1;
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            s = i;
            break;
        }
    }

    if (s == -1) {
        ans.push_back(-1);
        return ans;
    }

    for (int i = n - 1; i > 0; i--) {
        if (a[i] < a[i - 1]) {
            e = i;
            break;
        }
    }

    int mn = a[s];
    int mx = a[s];
    for (int i = s; i <= e; i++) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    int l = 0, r = n - 1;
    for (int i = 0; i <= s; i++) {
        if (a[i] > mn) {
            l = i;
            break;
        }
    }

    for (int i = n - 1; i >= e; i--) {
        if (a[i] < mx) {
            r = i;
            break;
        }
    }
    

    ans.push_back(l);
    ans.push_back(r);

    return ans;
}




