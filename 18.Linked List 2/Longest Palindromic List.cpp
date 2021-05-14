/*

Longest Palindromic List
Problem Description

Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list.

A palindrome list is a list that reads the same backward and forward.

Expected memory complexity : O(1)



Problem Constraints
1 <= length of the linked list <= 2000

1 <= Node value <= 100



Input Format
The only argument given is head pointer of the linked list.



Output Format
Return the length of the longest palindrome list.



Example Input
Input 1:

 2 -> 3 -> 3 -> 3
Input 2:

 2 -> 1 -> 2 -> 1 ->  2 -> 2 -> 1 -> 3 -> 2 -> 2


Example Output
Output 1:

 3
Output 2:

 5


Example Explanation
Explanation 1:

 3 -> 3 -> 3 is largest palindromic sublist
Explanation 2:

 2 -> 1 -> 2 -> 1 -> 2 is largest palindromic sublist.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* a) {

    ListNode *cur = a;
    ListNode *p1, *p2;
    ListNode *prev = NULL, *next;

    int ans = 0;
    int cnt = 0;

    while (cur != NULL) {

        // Frst lets check for the even length palindrome
        // so no middle element

        p1 = prev;
        p2 = cur;
        cnt = 0;
        while (p1 and p2 and p1->val == p2->val) {
            cnt += 2;
            p1 = p1->next;
            p2 = p2->next;
        }

        ans = max(ans, cnt);

        // now check for the odd length palindrome
        // which means there will be an middle element

        cnt = 1;
        p1 = prev;
        p2 = cur->next;
        while (p1 and p2 and p1->val == p2->val) {
            cnt += 2;
            p1 = p1->next;
            p2 = p2->next;
        }

        ans = max(ans, cnt);

        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return ans;
}
