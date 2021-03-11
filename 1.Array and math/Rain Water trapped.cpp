/*

Problem : https://www.interviewbit.com/problems/rain-water-trapped/

Rain Water Trapped
Problem Description

Given a vector A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Problem Constraints
1 <= |A| <= 100000

Input Format
First and only argument is the vector A

Output Format
Return one integer, the answer to the question

Example Input
Input 1:

A = [0, 1, 0, 2]
Input 2:

A = [1, 2]


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

1 unit is trapped on top of the 3rd element.
Explanation 2:

No water is trapped.
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


/*
    O(1) space complexity and O(n) time complexity solution
*/

int Solution::trap(const vector<int> &a) {

    if (a.size() == 0) {
        return 0;
    }

    int n = a.size();

    int leftmx = 0;
    int rightmx = 0;

    int index = -1;
    int biggest = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > biggest) {
            biggest = a[i];
            index = i;
        }
    }

    int ans = 0;

    for (int i = 0; i < index; i++) {
        ans += max(0, min(leftmx, biggest) - a[i]);
        leftmx = max(leftmx , a[i]);
    }

    for (int i = n - 1; i > index; i--) {
        ans += max(0, min(biggest, rightmx) - a[i]);
        rightmax = max(rightmx, a[i]);
    }

    return ans;
}
