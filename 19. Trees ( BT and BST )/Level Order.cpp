/**

Level Order
Problem Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:

 [
   [1]
   [6, 2]
   [3]
 ]


Example Explanation
Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.


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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::levelOrder(TreeNode* a) {

    vector<vector<int>> ans;

    if (a == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(a);
    while (!q.empty()) {

        int n = q.size();
        vector<int> curLevel;

        for (int i = 0; i < n; i++) {

            TreeNode *cur = q.front();
            q.pop();

            curLevel.push_back(cur->val);

            if (cur->left) {
                q.push(cur->left);
            }

            if (cur->right) {
                q.push(cur->right);
            }

        }

        ans.push_back(curLevel);
    }

    return ans;
}
