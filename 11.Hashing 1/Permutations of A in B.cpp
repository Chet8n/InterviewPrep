/*
Permutations of A in B
Problem Description

You are given two strings A and B of size N and M respectively.

You have to find the count of all permutations of A present in B as a substring. You can assume a string will have only lowercase letters.



Problem Constraints
1 <= N < M <= 105



Input Format
Given two argument, A and B of type String.



Output Format
Return a single Integer, i.e number of permutations of A present in B as a substring.



Example Input
Input 1:

 A = "abc"
 B = "abcbacabc"
Input 2:

 A = "aca"
 B = "acaa"


Example Output
Output 1:

 5
Output 2:

 2


Example Explanation
Explanation 1:

 Permutations of A that are present in B as substring are:
    1. abc
    2. cba
    3. bac
    4. cab
    5. abc
    So ans is 5.
Explanation 2:

 Permutations of A that are present in B as substring are:
    1. aca
    2. caa

*/
int Solution::solve(string a, string b) {

    int na = a.length();
    int nb = b.length();
    int cnt = 0;

    vector<int> ma(256, 0);
    vector<int> mb(256, 0);

    auto ok = [&]()-> bool{
        for (int i = 0; i < 256; i++) {
            if (ma[i] != mb[i]) {
                return false;
            }
        }
        return true;
    };

    if (na > nb) {
        return 0;
    }

    for (int i = 0; i < na; i++) {
        ma[a[i]]++;
        mb[b[i]]++;
    }

    for (int i = na; i < nb; i++) {
        if (ok()) {
            cnt++;
        }
        mb[b[i - na]]--;
        mb[b[i]]++;
    }

    if (ok()) {
        cnt++;
    }

    return cnt;
}
