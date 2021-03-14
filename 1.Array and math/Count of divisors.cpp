/*
Count of divisors
Problem Description

Given an array of integers A, find and return the count of divisors of each element of the array.

NOTE: Order of the resultant array should be same as the input array.



Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 106



Input Format
The only argument given is the integer array A.



Output Format
Return the count of divisors of each element of the array in the form of an array.



Example Input
Input 1:

 A = [2, 3, 4, 5]
Input 2:

 A = [8, 9, 10]


Example Output
Output 1:

 [2, 2, 3, 2]
Output 1:

 [4, 3, 4]


Example Explanation
Explanation 1:

 The number of divisors of 2 : [1, 2], 3 : [1, 3], 4 : [1, 2, 4], 5 : [1, 5]
 So the count will be [2, 2, 3, 2].
Explanation 2:

 The number of divisors of 8 : [1, 2, 4, 8], 9 : [1, 3, 9], 10 : [1, 2, 5, 10]
 So the count will be [4, 3, 4].


 */

vector<int> Solution::solve(vector<int> &a) {

    using ll = long long int;
    int N = *max_element(a.begin(), a.end());
    vector<int> p(N + 5, 1);
    vector<int> primes;

    p[0] = p[1] = 0;

    for (ll i = 2; i <= N; i++) {
        if (p[i] == 1) {
            primes.push_back(i);
            for (ll j = i * i; j <= N; j += i) {
                p[j] = 0;
            }
        }
    }

    int n = a.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        ll num = a[i];
        ll ans = 1;
        for (int j = 0; j < primes.size(); j++) {
            ll cur = primes[j];
            if (cur * cur * cur > num)
                break;

            ll cnt = 1;
            while (num % cur == 0) {
                num /= cur;
                cnt++;
            }

            ans *= cnt;


        }
        if (p[num] == 1) {
            ans *= 2;
        } else {
            ll sq = sqrt(num);
            if (p[sq] == 1 and sq * sq == num) {
                ans *= 3;
            } else if (num != 1) {
                ans *= 4;
            }
        }

        res[i] = ans;

    }

    return res;

}

