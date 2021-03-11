/*
First Missing Integer

Problem Description

Given an unsorted integer array A of size N. Find the first missing positive integer.

Note: Your algorithm should run in O(n) time and use constant space.



Problem Constraints
1 <= N <= 1000000

-109 <= A[i] <= 109



Input Format
First argument is an integer array A.



Output Format
Return an integer denoting the first missing positive integer.



Example Input
Input 1:

[1, 2, 0]
Input 2:

[3, 4, -1, 1]
Input 3:

[-8, -7, -6]


Example Output
Output 1:

3
Output 2:

2
Output 3:

1


Example Explanation
Explanation 1:

A = [1, 2, 0]
First positive integer missing from the array is 3.

*/

int Solution::firstMissingPositive(vector<int> &a) {

	/**

	- So the idea is to solve the q in o(n) time complexity and o(1)  space complexity
	- whenever we come accross num 1 <= a[i] <= n we swap that num with number in position a[a[i]]
	- now the frst pos in which a[pos] != pos is the ans

	**/

	int n = a.size();
	for (int i = 0; i < n; i++) {
		while (a[i] >= 1 and a[i] <= n and a[i] != a[a[i] - 1]) {
			swap(a[i], a[a[i] - 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			return i + 1;
		}
	}

	return n + 1;

}
