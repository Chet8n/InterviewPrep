/*
SIXLETS
Problem Description

Given a array of integers A of size N and an integer B.

Return number of non-empty subsequences of A of size B having sum <= 1000.



Problem Constraints
1 <= N <= 20

1 <= A[i] <= 1000

1 <= B <= N



Input Format
The first argument given is the integer array A.

The second argument given is the integer B.



Output Format
Return number of subsequences of A of size B having sum <= 1000.



Example Input
Input 1:

    A = [1, 2, 8]
    B = 2
Input 2:

    A = [5, 17, 1000, 11]
    B = 4


Example Output
Output 1:

3
Output 2:

0


Example Explanation
Explanation 1:

 {1, 2}, {1, 8}, {2, 8}
Explanation 1:

 No valid subsequence
*/

int Solution::solve(vector<int> &a, int b) {

    int n = a.size();
    auto go = [&](int cnt, int ind, int sum, const auto & self) {

        if (cnt == b) {
            if (sum <= 1000) {
                return 1;
            } else {
                return 0;
            }
        }

        if (ind >= n) {
            return 0;
        }

        // 2 options here
        // choose the current element
        int ans = 0;
        ans += self(cnt + 1, ind + 1, sum + a[ind], self);
        ans += self(cnt, ind + 1, sum, self);

        return ans;

    };

    int res = go(0, 0, 0, go);
    return res;

}

