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

    ListNode *mid = a;
    ListNode *fp = a;
    ListNode *prev = NULL;

    while (fp != NULL and fp->next != NULL) {
        prev = mid;
        mid = mid->next;
        fp = fp->next->next;
    }

    // now we have mid point, now make 2 seperate linked list,
    // from head to mid and mid->next to tail, and reverse the later
    // such that it is from tail to mid->next
    // then alternately pick from each linked list

    prev->next = NULL;
    prev = NULL;
    ListNode *scur = mid;
    ListNode *sprev = NULL;
    ListNode *snext = scur->next;

    while (scur) {
        snext = scur->next;
        scur->next = sprev;
        sprev = scur;
        scur = snext;
    }

    ListNode *shead = sprev;
    scur = sprev;
    ListNode *cur = a;
    ListNode *temp;
    ListNode *stemp;

    while (cur and scur) {
        prev = cur;
        sprev = scur;
        temp = cur->next;
        stemp = scur->next;

        cur->next = scur;
        if (temp)
            scur->next = temp;
        cur = temp;
        scur = stemp;

    }

    return a;
}
