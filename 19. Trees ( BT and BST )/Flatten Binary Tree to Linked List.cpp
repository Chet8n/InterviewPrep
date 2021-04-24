/**

Flatten Binary Tree to Linked List
Problem Description

Given a binary tree A, flatten it to a linked list in-place.

The left child of all nodes should be NULL.



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the head of tree A.



Output Format
Return the linked-list after flattening.



Example Input
Input 1:

     1
    / \
   2   3
Input 2:

         1
        / \
       2   5
      / \   \
     3   4   6


Example Output
Output 1:

1
 \
  2
   \
    3
Output 2:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


Example Explanation
Explanation 1:

 Tree flattening looks like this.
Explanation 2:

 Tree flattening looks like this.



**/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void go(TreeNode *a) {

    if (a == NULL) {
        return;
    }

    if (a->left != NULL) {
        go(a->left);

        TreeNode *temp = a->right;
        a->right = a->left;
        a->left = NULL;

        TreeNode *it = a->right;
        while (it->right) {
            it = it->right;
        }
        it->right = temp;
    }

    go(a->right);
}

TreeNode* Solution::flatten(TreeNode* a) {

    go(a);

    return a;
}
