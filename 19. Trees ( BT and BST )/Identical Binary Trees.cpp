/**

Identical Binary Trees
Problem Description

Given two binary trees, check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First argument is a root node of first tree, A.

Second argument is a root node of second tree, B.



Output Format
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.



Example Input
Input 1:

   1       1
  / \     / \
 2   3   2   3
Input 2:

   1       1
  / \     / \
 2   3   3   3


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Both trees are structurally identical and the nodes have the same value.
Explanation 2:

 Value of left child of the tree is different.



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
bool go(TreeNode *a, TreeNode *b) {

    if (a == NULL and b == NULL) {
        return true;
    }

    if (a == NULL or b == NULL) {
        return false;
    }

    if (a->val != b->val) {
        return false;
    }

    bool ok = (go(a->left, b->left) and go(a->right, b->right));

    return ok;
}

int Solution::isSameTree(TreeNode* a, TreeNode* b) {

    bool ans = go(a, b);

    return (ans ? 1 : 0);
}


