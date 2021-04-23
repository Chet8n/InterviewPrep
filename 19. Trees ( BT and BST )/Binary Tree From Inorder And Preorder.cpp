/**

Binary Tree From Inorder And Preorder
Problem Description

Given preorder and inorder traversal of a tree, construct the binary tree.

NOTE: You may assume that duplicates do not exist in the tree.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First argument is an integer array A denoting the preorder traversal of the tree.

Second argument is an integer array B denoting the inorder traversal of the tree.



Output Format
Return the root node of the binary tree.



Example Input
Input 1:

 A = [1, 2, 3]
 B = [2, 1, 3]
Input 2:

 A = [1, 6, 2, 3]
 B = [6, 1, 3, 2]


Example Output
Output 1:

   1
  / \
 2   3
Output 2:

   1
  / \
 6   2
    /
   3


Example Explanation
Explanation 1:

 Create the binary tree and return the root node of the tree.


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

TreeNode* go(vector<int> &pre, vector<int> &in, int s, int e, int &rootIndex, map<int, int> &m) {

    if (s > e) {
        return NULL;
    }

    TreeNode *parHere = new TreeNode(pre[rootIndex]);
    rootIndex++;
    if (s == e) {
        return parHere;
    }

    int index = m[parHere->val];
    parHere->left = go(pre, in, s, index - 1, rootIndex, m);
    parHere->right = go(pre, in, index + 1, e, rootIndex, m);

    return parHere;

}


TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {

    int n = preorder.size();
    int p = 0;

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[inorder[i]] = i;
    }

    return go(preorder, inorder, 0, n - 1, p, m);
}

