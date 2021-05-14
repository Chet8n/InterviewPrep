/*

N integers containing only 1, 2 & 3
Problem Description

Given an integer A. Find and Return first positive A integers in ascending order containing only digits 1, 2 and 3.

NOTE: All the A integers will fit in 32 bit integer.



Problem Constraints
1 <= A <= 29500



Input Format
The only argument given is integer A.



Output Format
Return an integer array denoting the first positive A integers in ascending order containing only digits 1, 2 and 3.



Example Input
Input 1:

 A = 3
Input 2:

 A = 7


Example Output
Output 1:

 [1, 2, 3]
Output 2:

 [1, 2, 3, 11, 12, 13, 21]


Example Explanation
Explanation 1:

 Output denotes the first 3 integers that contains only digits 1, 2 and 3.
Explanation 2:

 Output denotes the first 3 integers that contains only digits 1, 2 and 3.

*/

vector<int> Solution::solve(int a) {

	queue<int> q;
	int cnt = 0;
	vector<int> ans;
	q.push(1);
	cnt++;

	ans.push_back(1);
	if (cnt == a) {
		return ans;
	}

	q.push(2);
	cnt++;
	ans.push_back(2);
	if (cnt == a) {
		return ans;
	}

	q.push(3);
	cnt++;
	ans.push_back(3);
	if (cnt == a) {
		return ans;
	}

	while (cnt < a) {
		for (int i = 1; i <= 3; i++) {
			int ref = q.front();
			ref = ref * 10 + i;
			q.push(ref);
			ans.push_back(ref);
			cnt++;
			if (cnt == a) {
				break;
			}
		}
		q.pop();
	}

	return ans;
}
