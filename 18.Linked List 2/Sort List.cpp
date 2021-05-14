/*

Sort List
Problem Description

Sort a linked list, A in O(n log n) time using constant space complexity.



Problem Constraints
0 <= |A| = 105



Input Format
The first and the only arugment of input contains a pointer to the head of the linked list, A.



Output Format
Return a pointer to the head of the sorted linked list.



Example Input
Input 1:

A = [3, 4, 2, 8]
Input 2:

A = [1]


Example Output
Output 1:

[2, 3, 4, 8]
Output 2:

[1]


Example Explanation
Explanation 1:

 The sorted form of [3, 4, 2, 8] is [2, 3, 4, 8].
Explanation 2:

 The sorted form of [1] is [1].


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode *a, ListNode *b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }

    ListNode *head = NULL;

    if (a->val < b->val) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }

    ListNode *cur = head;

    while (a and b) {
        if (a->val < b->val) {
            cur->next = a;
            a = a->next;
        } else {
            cur->next = b;
            b = b->next;
        }

        cur = cur->next;
    }

    if (a) {
        cur->next = a;
    } else {
        cur->next = b;
    }

    return head;
}


ListNode* Solution::sortList(ListNode* a) {

    if (a == NULL or a->next == NULL) {
        return a;
    }

    ListNode *sp = a;
    ListNode *fp = a->next;

    while (fp and fp->next) {
        sp = sp->next;
        fp = fp->next->next;
    }

    ListNode *p1 = a;
    ListNode *p2 = sp->next;
    sp->next = NULL;

    return merge(sortList(p1), sortList(p2));

}

