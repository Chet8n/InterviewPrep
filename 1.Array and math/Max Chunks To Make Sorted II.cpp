/*
Max Chunks To Make Sorted II

Problem Description

Given an array of integers (not necessarily distinct) A, if we split the array into some number of "chunks" (partitions), and individually sort each chunk. After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?



Problem Constraints
1 <= N <= 100000
-109 <= A[i] <= 109



Input Format
The only argument given is the integer array A.



Output Format
Return the maximum number of chunks that we could have made.



Example Input
 A = [2, 0, 1, 2]


Example Output
 2


Example Explanation
 We can split the array into two subarray one consisting element [2,0,1] and second one with only element [2].
 Sort them individually and concat them. The result will be sorted.
 */

int Solution::solve(vector<int> &a) {

	using ll = long long int;
	int n = a.size();
	vector<int> b;
	b = a;
	sort(b.begin(), b.end());

	ll sum1 = 0;
	ll sum2 = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		sum1 += a[i];
		sum2 += b[i];
		if (sum1 == sum2) {
			cnt++;
		}
	}

	return cnt;

}
