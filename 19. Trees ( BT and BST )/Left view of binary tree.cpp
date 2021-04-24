/**

Left view of binary tree
Problem Description

Given a binary tree of integers. Return an array of integers representing the left view of the Binary tree.

Left view of a Binary Tree is a set of nodes visible when the tree is visited from Left side

NOTE: The value comes first in the array which have lower level.



Problem Constraints
1 <= Number of nodes in binary tree <= 100000

0 <= node values <= 109



Input Format
First and only argument is a root node of the binary tree, A.



Output Format
Return an integer array denoting the left view of the Binary tree.



Example Input
Input 1:

            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8
Input 2:

            1
           /  \
          2    3
           \
            4
             \
              5


Example Output
Output 1:

 [1, 2, 4, 8]
Output 2:

 [1, 2, 4, 5]


Example Explanation
Explanation 1:

 The Left view of the binary tree is returned.



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
vector<int> Solution::solve(TreeNode* a) {

    vector<int> ans;
    if (a == NULL) {
        return ans;
    }

    map<int , int> m;
    queue<pair<TreeNode*, int>> q;
    q.push({a, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        TreeNode *node = cur.first;
        int level = cur.second;
        if (m.find(level) == m.end()) {
            m[level] = node->val;
        }

        if (node->left) {
            q.push({node->left, level + 1});
        }

        if (node->right) {
            q.push({node->right, level + 1});
        }

    }

    for (auto x : m) {
        ans.push_back(x.second);
    }

    return ans;
}
