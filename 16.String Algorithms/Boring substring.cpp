/*

Boring substring
Problem Description

Given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there is no boring substring in A.

A boring substring has the following properties:

Its length is 2.
Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.(If the first character is C then the next character can be either (C+1) or (C-1)).
Return 1 if it possible to rearrange the letters of A such that there are no boring substring in A, else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
The only argument given is string A.



Output Format
Return 1 if it possible to rearrange the letters of A such that there are no boring substring in A, else return 0.



Example Input
Input 1:

 A ="abcd"
Input 2:

 A = "aab"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 String A can be rearranged into "cadb" or "bdac" 
Explanation 2:

 No arrangement of string A can make it free of boring substrings.

*/

int Solution::solve(string a) {

    int n = a.length();
    string odd = "";
    string even = "";

    for (int i = 0; i < n; i++) {
        int num = a[i] - 'a';
        if (num & 1) {
            odd += a[i];
        } else {
            even += a[i];
        }
    }

    if (odd.length() == 0) {
        return 1;
    } else if (even.length() == 0) {
        return 1;
    }

    char minodd = 'z', maxodd = 'a';
    char mineven = 'z', maxeven = 'a';

    for (auto x : odd) {
        minodd = min(minodd, x);
        maxodd = max(maxodd, x);
    }

    for (auto x : even) {
        mineven = min(mineven, x);
        maxeven = max(maxeven, x);
    }

    string ans = "";
    if (abs(minodd - maxeven) > 1) {
        return 1;
    } else if (abs(maxodd - mineven) > 1) {
        return 1;
    }

    return 0;

}
