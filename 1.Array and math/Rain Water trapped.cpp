/*

Problem : https://www.interviewbit.com/problems/rain-water-trapped/

Rain Water Trapped
Given n non-negative integers representing an elevation
map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining..

For Example
Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1:

    In this case, 6 units of rain water (blue section) are being trapped.

*/

int Solution::trap(const vector<int> &a) {

    if (a.size() == 0) {
        return 0;
    }

    int n = a.size();

    vector<int> prefixMax(n + 5, 0);
    vector<int> suffixMax(n + 5, 0);
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], a[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], a[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int x = min(prefixMax[i], suffixMax[i]);
        if (x >= a[i]) {
            ans += x - a[i];
        }
    }
    
    return ans;
   
}
