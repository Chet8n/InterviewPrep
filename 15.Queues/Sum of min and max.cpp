/*

Sum of min and max
Problem Description

Given an array A of both positive and negative integers.

Your task is to compute sum of minimum and maximum elements of all sub-array of size B.

NOTE: Since the answer can be very large, you are required to return the sum modulo 109 + 7.



Problem Constraints
1 <= size of array A <= 105

-109 <= A[i] <= 109

1 <= B <= size of array



Input Format
The first argument denotes the integer array A.
The second argument denotes the value B



Output Format
Return an integer that denotes the required value.



Example Input
Input 1:

 A = [2, 5, -1, 7, -3, -1, -2]
 B = 4
Input 2:

 A = [2, -1, 3]
 B = 2


Example Output
Output 1:

 18
Output 2:

 3


Example Explanation
Explanation 1:

 Subarrays of size 4 are :
    [2, 5, -1, 7],   min + max = -1 + 7 = 6
    [5, -1, 7, -3],  min + max = -3 + 7 = 4
    [-1, 7, -3, -1], min + max = -3 + 7 = 4
    [7, -3, -1, -2], min + max = -3 + 7 = 4
    Sum of all min & max = 6 + 4 + 4 + 4 = 18
Explanation 2:

 Subarrays of size 2 are :
    [2, -1],   min + max = -1 + 2 = 1
    [-1, 3],   min + max = -1 + 3 = 2
    Sum of all min & max = 1 + 2 = 3

*/

int Solution::solve(vector<int> &a, int b) {

	int n = a.size();
	using ll = long long int;
	ll ans = 0;
	ll mod = 1e9 + 7;

	deque<int> mx, mn;

	auto pushmx = [&](int i) {
		while (!mx.empty() and a[mx.back()] <= a[i]) {
			mx.pop_back();
		}

		while (!mx.empty() and mx.front() <= i - b) {
			mx.pop_front();
		}

		mx.push_back(i);
	};

	auto pushmn = [&](int i) {
		while (!mn.empty() and a[mn.back()] >= a[i]) {
			mn.pop_back();
		}

		while (!mn.empty() and mn.front() <= i - b) {
			mn.pop_front();
		}

		mn.push_back(i);
	};

	for (int i = 0; i < b; i++) {
		pushmx(i);
		pushmn(i);
	}

	ans += a[mx.front()];
	ans += a[mn.front()];
	ans = ((ans % mod) + mod) % mod;


	for (int i = b; i < n; i++) {
		pushmx(i);
		pushmn(i);
		ans += a[mx.front()];
		ans += a[mn.front()];
		ans = ((ans % mod) + mod) % mod;
	}

	return ans;
}
