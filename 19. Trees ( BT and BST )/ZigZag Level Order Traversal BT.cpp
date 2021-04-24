/**

ZigZag Level Order Traversal BT
Problem Description

Given a binary tree, return the zigzag level order traversal of its nodes values. (ie, from left to right, then right to left for the next level and alternate between).



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
   [20, 9],
   [15, 7]
 ]
Output 2:

 [
   [1]
   [2, 6]
   [3]
 ]


Example Explanation
Explanation 1:

 Return the 2D array. Each row denotes the zigzag traversal of each level.


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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* a) {

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

    for (int i = 1; i < ans.size(); i += 2) {
        reverse(ans[i].begin(), ans[i].end());
    }

    return ans;
}

/**

- Interview expected solution may be :


 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > output;
    if (root == NULL) return output;
    stack<TreeNode*> cur_layer;
    cur_layer.push(root);
    stack<TreeNode*> next_layer;
    vector<int> layer_output;
    int d = 0; // 0: left to right; 1: right to left.

    while (!cur_layer.empty()) {
        TreeNode* node = cur_layer.top();
        cur_layer.pop();
        layer_output.push_back(node->val);
        if (d == 0) {
            if (node->left != NULL) next_layer.push(node->left);
            if (node->right != NULL) next_layer.push(node->right);
        } else {
            if (node->right != NULL) next_layer.push(node->right);
            if (node->left != NULL) next_layer.push(node->left);
        }

        if (cur_layer.empty()) {
            output.push_back(layer_output);
            layer_output.clear();
            cur_layer.swap(next_layer);
            if (d == 1) d = 0;
            else d = 1;
        }
    }
    return output;

}

** /
