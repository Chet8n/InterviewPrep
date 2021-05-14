/*

Clone a Linked List
Problem Description

Given a doubly linked list of integers with one pointer of each node pointing to the next node (just like in a single link list) while the second pointer, however, can point to any node in the list and not just the previous node.

You have to create a copy of this list and return the head pointer of the duplicated list.



Problem Constraints
1 <= length of the list <= 100000

1 <= Value of node <= 100000



Input Format
The only argument given is head pointer of the doubly linked list.



Output Format
Return the head pointer of the duplicated list.



Example Input
Input 1:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1
Input 2:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1


Example Output
Output 1:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1
Output 2:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1


Example Explanation
Explanation 1:

 Just clone the given list.
Explanation 2:

 Just clone the given list


*/


/*
struct ListNode {
    int val;
    ListNode *next,*random;
    ListNode(int x) {
        val = x;
        next = random = NULL;
    }
};
*/
ListNode* clonelist(ListNode *a) {

    // You can use a hashmap and store adresses mapping of cloned to original list
    // but how to do it in o(1) space
    // the idea is to create new cloned nodes next to the original ones
    // ori -> copy -> ori -> copy -> . . .
    // now the solution must be looking easy ;)

    ListNode *cur = a, *next;
    while (cur) {
        next = cur->next;
        cur->next = new ListNode(cur->val);
        cur->next->next = next;
        cur = next;
    }

    cur = a;
    while (cur) {
        if (cur->random != NULL) {
            cur->next->random = cur->random->next;
        } else {
            cur->next->random = NULL;
        }

        cur = cur->next->next;
    }

    ListNode *clone = a->next;
    ListNode *cloneHead = a->next;

    cur = a;

    while (clone->next->next) {
        clone = cur->next;
        next = clone->next;
        clone->next = clone->next->next;
        cur->next = next;
        cur = next;
    }

    return cloneHead;


}
