/*

Largest Rectangle in Histogram
Problem Description

Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the area of largest rectangle in the histogram.



Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:

Largest rectangle has area 2.

*/

int Solution::largestRectangleArea(vector<int> &a) {

	int n = a.size();

	/**

	- consider every block as minimum ht block in the subarray, and check
	whats the maximum area it can form
	- to find max area we need closest smaller ht block on the left and
	right, and that can be done using stacks easily
	- if i is my cur block and l and r are my left and right index resp,
	then cur_area is (r - l)*height[i]

	**/

	using ll = long long int;
	stack<int> s;

	// vector<int> left(n), right(n);
	// for (int i = n - 1; i >= 0; i--) {
	//     while (!s.empty() and a[s.top()] > a[i]) {
	//         left[s.top()] = i;
	//         s.pop();
	//     }
	//     s.push(i);
	// }

	// while (!s.empty()) {
	//     left[s.top()] = -1;
	//     s.pop();
	// }

	// for (int i = 0; i < n; i++) {
	//     while (!s.empty() and a[s.top()] > a[i]) {
	//         right[s.top()] = i;
	//         s.pop();
	//     }
	//     s.push(i);
	// }

	// while (!s.empty()) {
	//     right[s.top()] = n;
	//     s.pop();
	// }

	ll ans = 0;

	// for (int i = 0; i < n; i++) {
	//     ll here = (1LL * (right[i] - left[i] - 1) * a[i]);
	//     ans = max(ans, here);
	// }

	/**

	- a small trick here to calculate both left and right in a single loop

	**/
	for (int i = 0; i < n; i++) {

		while (!s.empty() and a[s.top()] > a[i]) {
			int tp = s.top();
			s.pop();

			ll here = a[tp] * (s.empty() ? i : i - s.top() - 1);
			ans = max(ans, here);

		}

		s.push(i);
	}

	int i = n;

	while (!s.empty()) {
		int tp = s.top();
		s.pop();

		ll here = a[tp] * (s.empty() ? i : i - s.top() - 1);
		ans = max(ans, here);

	}


	return ans;
}

