/*

MAX and MIN
Problem Description

Given an array of integers A .

value of a array = max(array) - min(array).

Calculate and return the sum of values of all possible subarrays of A % 109+7.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000



Input Format
The first and only argument given is the integer array A.



Output Format
Return the sum of values of all possible subarrays of A % 10^9+7.



Example Input
Input 1:

 A = [1]
Input 2:

 A = [4, 7, 3, 8]


Example Output
Output 1:

 0
Output 2:

 26


Example Explanation
Explanation 1:

Only 1 subarray exists. Its value is 0.
Explanation 2:

value ( [4] ) = 4 - 4 = 0
value ( [7] ) = 7 - 7 = 0
value ( [3] ) = 3 - 3 = 0
value ( [8] ) = 8 - 8 = 0
value ( [4, 7] ) = 7 - 4 = 3
value ( [7, 3] ) = 7 - 3 = 4
value ( [3, 8] ) = 8 - 3 = 5
value ( [4, 7, 3] ) = 7 - 3 = 4
value ( [7, 3, 8] ) = 8 - 3 = 5
value ( [4, 7, 3, 8] ) = 8 - 3 = 5
sum of values % 10^9+7 = 26

*/

int Solution::solve(vector<int> &a) {

	int n = a.size();
	using ll = long long int;
	ll mod = 1e9 + 7;
	vector<int> leftMin(n);
	vector<int> rightMin(n);
	vector<int> leftMax(n);
	vector<int> rightMax(n);

	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() and a[s.top()] > a[i]) {
			leftMin[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		leftMin[s.top()] = -1;
		s.pop();
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() and a[s.top()] < a[i]) {
			leftMax[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		leftMax[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() and a[s.top()] < a[i]) {
			rightMax[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		rightMax[s.top()] = n;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() and a[s.top()] > a[i]) {
			rightMin[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		rightMin[s.top()] = n;
		s.pop();
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ll contribution = (1LL * (i - leftMin[i]) * (rightMin[i] - i));
		ans -= 1LL * contribution * a[i];
		ans = ((ans % mod) + mod) % mod;
		contribution = (1LL * (i - leftMax[i]) * (rightMax[i] - i));
		ans += 1LL * contribution * a[i];
		ans = ((ans % mod) + mod) % mod;
	}

	return ans;

}
