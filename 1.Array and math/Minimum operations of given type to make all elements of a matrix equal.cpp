/*
Minimum operations of given type to make all elements of a matrix equal

Problem Description

Given a matrix of integers A of size N x M and an integer B.

In a single operation, B can be added to or subtracted from any element of the matrix.

Find and return the minimum number of operations required to make all the elements of the matrix equal and if it impossible return -1 instead.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N, M <= 1000
-1000 <= A[i] <= 1000
1 <= B <= 1000



Input Format
The first argument given is the integer matrix A. The second argument given is the integer B.



Output Format
Return the minimum number of operations required to make all the elements of the matrix equal and if it impossible return -1 instead.



Example Input
 A = [
        [0, 2, 8]
        [8, 2, 0]
        [0, 2, 8]
     ]
 B = 2


Example Output
 12


Example Explanation
 We can make all value equal to 2 by adding 2 one time to 0's and subtracting 2 three times from 8's.
 So there are all total 12 operations needed to be done.

*/

int Solution::solve(vector<vector<int> > &a, int b) {

	int n = a.size();
	int m = a[0].size();

	int mod;
	if (a[0][0] >= 0) {
		mod = a[0][0] % b;
	} else {
		mod = ((a[0][0] % b) + b) % b;
	}

	// now inorder for solution to be present, all modulo b of all a[i][j] == mod

	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v.push_back(a[i][j]);
			int here;
			if (a[i][j] >= 0) {
				here = a[i][j] % b;
			} else {
				here = ((a[i][j] % b) + b) % b;
			}
			if (here != mod) {
				return -1;
			}
		}
	}

	sort(v.begin(), v.end());

	// it always optimal to make all elements equal to the median
	int med = v[(n * m) / 2];
	int ans = 0;

	for (int i = 0; i < n * m; i++) {
		ans += abs(v[i] - med) / b;
	}

	// if there are 2 medians:
	// if n*m is even then they have 2 medians
	if ((n * m) % 2 == 0) {
		med = v[(n * m) / 2 - 1];
		int ans2 = 0;
		for (int i = 0; i < n * m; i++) {
			ans2 += abs(v[i] - med) / b;
		}
		ans = min(ans, ans2);
	}

	return ans;

}
