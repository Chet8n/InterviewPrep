/*

Add Two Numbers as Lists
Problem Description

You are given two linked lists, A and B representing two non-negative numbers.

The digits are stored in reverse order and each of their nodes contain a single digit.

Add the two numbers and return it as a linked list.



Problem Constraints
1 <= |A|, |B| <= 105



Input Format
The first argument of input contains a pointer to the head of linked list A.

The second argument of input contains a pointer to the head of linked list B.



Output Format
Return a pointer to the head of the required linked list.



Example Input
Input 1:

 
 A = [2, 4, 3]
 B = [5, 6, 4]
Input 2:

 
 A = [9, 9]
 B = [1]


Example Output
Output 1:

 
 [7, 0, 8]
Output 2:

 
 [0, 0, 1]


Example Explanation
Explanation 1:

 A = 342 and B = 465. A + B = 807. 
Explanation 2:

 A = 99 and B = 1. A + B = 100. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* a, ListNode* b) {

    if (a == NULL) {
        return b;
    }

    if (b == NULL) {
        return a;
    }

    ListNode *ans = NULL;
    ListNode *cura = a;
    ListNode *curb = b;

    ListNode *head;

    int carry = 0, sum = 0, val = 0;
    while (cura and curb) {
        sum = cura->val + curb->val + carry;
        carry = sum / 10;
        val = sum % 10;

        ListNode *now = new ListNode(val);

        if (ans == NULL) {
            ans = now;
            head = ans;
        } else {
            ans->next = now;
            ans = ans->next;
        }

        cura = cura->next;
        curb = curb->next;
    }

    if (cura == NULL) {
        while (curb) {
            sum = curb->val + carry;
            carry = sum / 10;
            val = sum % 10;

            ListNode *now = new ListNode(val);

            ans->next = now;
            ans = ans->next;

            curb = curb->next;
        }
    } else if (curb == NULL) {
        while (cura) {
            sum = cura->val + carry;
            carry = sum / 10;
            val = sum % 10;

            ListNode *now = new ListNode(val);

            ans->next = now;
            ans = ans->next;

            cura = cura->next;
        }
    }

    if (carry) {
        ListNode *now = new ListNode(carry);

        ans->next = now;
        ans = ans->next;
    }

    return head;
}
