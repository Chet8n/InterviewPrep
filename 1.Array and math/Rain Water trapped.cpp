/*
Rain Water Trapped
Given n non-negative integers representing an elevation
map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining..

For Example
Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1:

    In this case, 6 units of rain water (blue section) are being trapped.

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef pair<int, int> pi;

#define all(x) (x).begin(), (x).end()

#define endl "\n"

#define pb push_back

#define mp make_pair

#define F first

#define S second

#define ar array

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefixMax(n + 5, 0);
    vector<int> suffixMax(n + 5, 0);
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], a[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], a[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int x = min(prefixMax[i], suffixMax[i]);
        if (x >= a[i]) {
            ans += x - a[i];
        }
    }
    cout << ans << endl;

}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}

