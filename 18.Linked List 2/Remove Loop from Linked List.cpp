/*

Remove Loop from Linked List
Problem Description

Given a linked list which contains some loop.

You need to find the node, which creates a loop, and break it by making the node point to NULL.



Problem Constraints
1 <= number of nodes <= 1000



Input Format
Only argument is the head of the linked list.



Output Format
return the head of the updated linked list.



Example Input
Input 1:


1 -> 2
^    |
| - -
Input 2:

3 -> 2 -> 4 -> 5 -> 6
          ^         |
          |         |
          - - - - - -


Example Output
Output 1:

 1 -> 2 -> NULL
Output 2:

 3 -> 2 -> 4 -> 5 -> 6 -> NULL


Example Explanation
Explanation 1:

 Chain of 1->2 is broken.
Explanation 2:

 Chain of 4->6 is broken.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* a) {

	if (a == NULL or a->next == NULL) {
		return a;
	}

	ListNode *fp = a;
	ListNode *sp = a;

	while (fp and fp->next) {
		sp = sp->next;
		fp = fp->next->next;
		if (sp == fp) {
			break;
		}
	}

	// so now if sp == fp that means there is a loop

	if (sp == fp) {
		sp = a;
		if (sp == fp) {

			// if the head is the begining node of loop
			while (fp->next != sp) {
				fp = fp->next;
			}
		} else {
			while (sp->next != fp->next) {
				sp = sp->next;
				fp = fp->next;
			}
		}
		fp->next = NULL;
	}


	return a;

}

