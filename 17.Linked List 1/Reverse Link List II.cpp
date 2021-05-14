/*

Reverse Link List II
Problem Description

Reverse a linked list A from position B to C.

NOTE: Do it in-place and in one-pass.



Problem Constraints
1 <= |A| <= 106

1 <= B <= C <= |A|



Input Format
The first argument contains a pointer to the head of the given linked list, A.

The second arugment contains an integer, B.

The third argument contains an integer C.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

 A = 1 -> 2 -> 3 -> 4 -> 5
 B = 2
 C = 4

Input 2:

 A = 1 -> 2 -> 3 -> 4 -> 5
 B = 1
 C = 5


Example Output
Output 1:

 1 -> 4 -> 3 -> 2 -> 5
Output 2:

 5 -> 4 -> 3 -> 2 -> 1


Example Explanation
Explanation 1:

 In the first example, we want to reverse the highlighted part of the given linked list : 1 -> 2 -> 3 -> 4 -> 5 
 Thus, the output is 1 -> 4 -> 3 -> 2 -> 5 
Explanation 2:

 In the second example, we want to reverse the highlighted part of the given linked list : 1 -> 4 -> 3 -> 2 -> 5  
 Thus, the output is 5 -> 4 -> 3 -> 2 -> 1 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* a, int b, int c) {

    if (a == NULL) {
        return a;
    }

    int index = 1;

    /**

    - Terminology

    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
                   b         c

    - let head to b-1 be first part. p-c be sec and c+1 to tail be third
    - fend = end of frst part
    - sstart = sec start
    - send = sec end
    - tstart = third start

    **/

    ListNode *fend = NULL;
    ListNode *sstart;
    ListNode *send;
    ListNode *tstart;
    ListNode *cur = a;
    ListNode *prev = NULL;
    ListNode *next = cur->next;

    while (index <= b) {
        if (index == b - 1) {
            fend = cur;
        }
        if (index == b) {
            sstart = cur;
        }

        prev = cur;
        cur = cur->next;
        index++;
    }

    while (index <= c) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        if (index == c) {
            send = prev;
            tstart = cur;
            sstart->next = tstart;
            if (fend) {
                fend->next = send;
            } else {
                a = send;
            }
        }
        index++;
    }

    return a;


}
