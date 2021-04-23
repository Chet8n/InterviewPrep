/**

Min Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.


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

int go(TreeNode *a) {
    if (a == NULL) {
        return 0;
    }

    if (a->left == NULL and a->right == NULL) {
        return 1;
    }

    if (a->left == NULL) {
        return 1 + go(a->right);
    }

    if (a->right == NULL) {
        return 1 + go(a->left);
    }

    return 1 + min(go(a->left), go(a->right));
}

int Solution::minDepth(TreeNode* a) {

    int ans = go(a);

    return ans;
}
