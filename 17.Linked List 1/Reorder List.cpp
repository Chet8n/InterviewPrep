/*

Reorder List
Problem Description

Given a singly linked list A

 A: A0 → A1 → … → An-1 → An 
reorder it to:

 A0 → An → A1 → An-1 → A2 → An-2 → … 
You must do this in-place without altering the nodes' values.



Problem Constraints
1 <= |A| <= 106



Input Format
The first and the only argument of input contains a pointer to the head of the linked list A.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

 A = [1, 2, 3, 4, 5] 
Input 2:

 A = [1, 2, 3, 4] 


Example Output
Output 1:

 [1, 5, 2, 4, 3] 
Output 2:

 [1, 4, 2, 3] 


Example Explanation
Explanation 1:

 The array will be arranged to [A0, An, A1, An-1, A2].
Explanation 2:

 The array will be arranged to [A0, An, A1, An-1, A2].

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* a) {

    if (a == NULL or a->next == NULL) {
        return a;
    }

    // step 1 : Find the mid point
    // this method will have frst part length <= second part length

    ListNode *fast = a;
    ListNode *slow = a;

    ListNode *prev;

    while (fast and fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2 : reverse the List from slow to end of Linked List

    ListNode *cur = slow;
    prev->next = NULL;
    prev = NULL;
    ListNode *next;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // step 3 : Get the reqd order:

    ListNode *scur = prev;
    cur = a;
    ListNode *snext;

    while (cur and scur) {
        next = cur->next;
        cur->next = scur;
        snext = scur->next;
        if (next)
            scur->next = next;

        cur = next;
        scur = snext;
    }

    return a;

}
