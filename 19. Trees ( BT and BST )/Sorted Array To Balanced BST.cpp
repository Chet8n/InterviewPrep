/**

Sorted Array To Balanced BST
Problem Description

Given an array where elements are sorted in ascending order, convert it to a height Balanced Binary Search Tree (BBST).

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



Problem Constraints
1 <= length of array <= 100000



Input Format
First argument is an integer array A.



Output Format
Return a root node of the Binary Search Tree.



Example Input
Input 1:

 A : [1, 2, 3]
Input 2:

 A : [1, 2, 3, 5, 10]


Example Output
Output 1:

      2
    /   \
   1     3
Output 2:

      3
    /   \
   2     5
  /       \
 1         10


Example Explanation
Explanation 1:

 You need to return the root node of the Binary Tree.

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
TreeNode* go(const vector<int> &a, int s, int e) {

    if (s > e) {
        return NULL;
    }

    int mid = (s + e) >> 1;

    TreeNode *root = new TreeNode(a[mid]);

    root->left = go(a, s, mid - 1);
    root->right = go(a, mid + 1, e);

    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &a) {

    int n = a.size();

    return go(a, 0, n - 1);
}


