/*
Repeat and Missing Number Array

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &a) {

	/**

    using ll = long long int;

    ll n = (int)a.size();
    
    ll sum = 0;
    ll sqsum = 0;
    for (int i = 0 ; i < n; i++) {
        sum += a[i];
        sqsum += (1LL *a[i] * a[i]);
    }

    ll asum = (n * (n + 1)) / 2;
    ll asqsum = (n * (n + 1) * (2 * n + 1)) / 6;

    ll sqdiff = asqsum - sqsum;
    ll sumdiff = asum - sum;

    ll sumxy = sqdiff / sumdiff;
    ll x = (sumxy + sumdiff) / 2;
    ll y = sumxy - x;

    vector<int> ans;
    ans.push_back(y);
    ans.push_back(x);

    return ans;
    
    int n = (int)a.size();
    using ll = long long int;

    **/


    /**

    - XOR of all elements and num from 1 to n will give x^y ( where x is rep num and y is missing num)
    - all numbers which have common set bit will go into 1 bucket and all other into other
    - then do same with numbers from [1 n]
    - now XOR of one bucket gives missing and other repeated

    **/

	/*** Alternate solution ***/

    int xy = 0;
    for (int i = 0; i < n; i++) {
        xy ^= a[i];
		xy ^= (i + 1);
    }

    int b1 = 0, b2 = 0;
    int setbit = 0;
    for (int i = 31; i >= 0; i--) {
        if (xy & (1 << i)) {
            setbit = (1 << i);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] & setbit) {
            b1 ^= a[i];
        } else {
            b2 ^= a[i];
        }

        int num = i + 1;
        if (num & setbit) {
            b1 ^= num;
        } else {
            b2 ^= num;
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (b1 == a[i]) {
            ans.push_back(b1);
            ans.push_back(b2);
            break;
        } else if (b2 == a[i]) {
            ans.push_back(b2);
            ans.push_back(b1);
            break;
        }
    }

    return ans;

}
