/*

Partition List
Problem Description

Given a linked list A and a value B, partition it such that all nodes less than B come before nodes greater than or equal to B.

You should preserve the original relative order of the nodes in each of the two partitions.



Problem Constraints
1 <= |A| <= 106

1 <= A[i], B <= 109



Input Format
The first argument of input contains a pointer to the head to the given linked list.

The second argument of input contains an integer, B.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

A = [1, 4, 3, 2, 5, 2]
B = 3
Input 2:

A = [1, 2, 3, 1, 3]
B = 2


Example Output
Output 1:

[1, 2, 2, 4, 3, 5]
Output 2:

[1, 1, 2, 3, 3]


Example Explanation
Explanation 1:

 [1, 2, 2] are less than B wheread [4, 3, 5] are greater than or equal to B.
Explanation 2:

 [1, 1] are less than B wheread [2, 3, 3] are greater than or equal to B.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* a, int b) {

    ListNode *p1 = new ListNode(0);
    ListNode *p2 = new ListNode(0);
    ListNode *cur1 = p1;
    ListNode *cur2 = p2;
    while (a) {
        if (a->val < b) {
            cur1->next = a;
            a = a->next;
            cur1 = cur1->next;
        } else {
            cur2->next = a;
            a = a->next;
            cur2 = cur2->next;
        }
    }

    cur1->next = p2->next;
    cur2->next = NULL;
    return p1->next;

}
