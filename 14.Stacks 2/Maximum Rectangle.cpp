/*

Maximum Rectangle
Given a 2D binary matrix of integers A containing 0's and 1's of size N x M.

Find the largest rectangle containing only 1's and return its area.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.


Input Format

The only argument given is the integer matrix A.
Output Format

Return the area of the largest rectangle containing only 1's.
Constraints

1 <= N, M <= 1000
0 <= A[i] <= 1
For Example

Input 1:
    A = [   [0, 0, 1]
            [0, 1, 1]
            [1, 1, 1]   ]
Output 1:
    4

Input 2:
    A = [   [0, 1, 0, 1]
            [1, 0, 1, 0]    ]
Output 2:
    1

*/

int maxRectInHistogram(vector<int> &a) {

	int n = a.size();

	stack<int> s;

	int ans = 0;

	for (int i = 0; i < n; i++) {

		while (!s.empty() and a[s.top()] > a[i]) {
			int tp = s.top();
			s.pop();

			int here = a[tp] * (s.empty() ? i : i - s.top() - 1);
			ans = max(ans, here);

		}

		s.push(i);
	}

	int i = n;

	while (!s.empty()) {
		int tp = s.top();
		s.pop();

		int here = a[tp] * (s.empty() ? i : i - s.top() - 1);
		ans = max(ans, here);

	}


	return ans;
}


int Solution::solve(vector<vector<int> > &a) {

	int n = a.size();
	int m = a[0].size();
	int ans = maxRectInHistogram(a[0]);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				a[i][j] += a[i - 1][j];
			}
		}
		ans = max(ans, maxRectInHistogram(a[i]));
	}

	return ans;

}
