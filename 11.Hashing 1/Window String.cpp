/*
Window String
Problem Description

Given a string A and a string B, find the window with minimum length in A which will contain all the characters in B in linear time complexity.
Note that when the count of a character c in B is x, then the count of c in minimum window in A should be at least x.

Note:

If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index )


Problem Constraints
1 <= size(A), size(B) <= 106



Input Format
First argument is a string A.
Second argument is a string B.



Output Format
Return a string denoting the minimum window.



Example Input
Input 1:

 A = "ADOBECODEBANC"
 B = "ABC"
Input 2:

 A = "Aa91b"
 B = "ab"


Example Output
Output 1:

 "BANC"
Output 2:

 "a91b"


Example Explanation
Explanation 1:

 "BANC" is a substring of A which contains all characters of B.
Explanation 2:

 "a91b" is the substring of A which contains all characters of B.

*/
string Solution::minWindow(string a, string b) {

    int inf = 1e9;
    int na = a.length();
    int nb = b.length();

    if (na < nb) {
        return "";
    }

    map<char, int> ma, mb;
    for (int i = 0; i < nb; i++) {
        mb[b[i]]++;
    }

    int s = 0;
    int sIndex = -1;
    int minLen = inf;
    int cnt = 0;
    for (int i = 0; i < na; i++) {
        ma[a[i]]++;
        if (ma[a[i]] <= mb[a[i]]) {
            cnt++;
        }

        if (cnt == nb) {
            while (ma[a[s]] > mb[a[s]] or mb[a[s]] == 0) {
                if (ma[a[s]] > mb[a[s]]) {
                    ma[a[s]]--;
                }
                s++;
            }

            int here = i - s + 1;
            if (minLen > here) {
                minLen = here;
                sIndex = s;
            }
        }
    }

    if (sIndex == -1) {
        return "";
    }

    string ans = a.substr(sIndex, minLen);

    return ans;

}
