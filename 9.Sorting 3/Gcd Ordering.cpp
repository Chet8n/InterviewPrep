/*
Gcd Ordering
Given an array of integers A, find and return the lexicographically greatest arrangement of A which follows the below rules:

If the size of A is less than 3 it is always possible to rearrange A.

A[i] = A[i-1] + GCD(A[i-1], A[i-2]) for all i > 2, where GCD(x, y) is greatest common factor of x and y.

Return the lexicographically greatest arrangement of A which follows the above rules, if it is not possible to rearrange A according to the above rules return -1.

Note: Lexicographically means in dictionary order, i.e. if two arrangemnets are compared based on dictionary position the arrangements which comes afterwards is said to be Lexicographically greater.


Input Format

The only argument given is the integer array A.
Output Format

Return the lexicographically greatest arrangement of A  which follows the above rules, 
if it is not possible to rearrange A according to the given rules return -1.
Constraints

1 <= length of the array <= 100000
0 <= A[i] <= 10^5
For Example

Input 1:
    A = [4, 6, 2, 5, 3]
Output 1:
     [2, 3, 4, 5, 6]

Input 2:
    A = [3, 8, 5]
Output 2:
    -1

×


*/
vector<int> Solution::solve(vector<int> &a) {

    sort(a.begin(), a.end());

    int n = a.size();
    
    if(n == 2){
        swap(a[1], a[0]);
        return a;
    }
    
    if(n == 1){
        return a;
    }

    /**

    - frst 2 elements can be any elements remaining all must be sorted
    - among frst 2 elements one element has to be the smallest

    **/

    bool select = false;
    int index = -1;

    for (int i = n - 1; i >= 2; i--) {
        if (a[i] != a[i - 1] + __gcd(a[i - 1], a[i - 2])) {
            if (select == false) {
                select = true;
                index = i;
            } else {
                vector<int> ans;
                ans = { -1};
                return ans;
            }
        }
    }

    if (select == false) {
        return a;
    }

    if (a[1] == a[0] + __gcd(a[0], a[index])) {
        vector<int> ans(n);
        ans[0] = a[index];
        ans[1] = a[0];
        int k = 2;
        for (int i = 1; i < n; i++) {
            if (i == index) {
                continue;
            }
            ans[k++] = a[i];
        }
        return ans;

    }

    vector<int> ans;
    ans = { -1};
    return ans;


}
