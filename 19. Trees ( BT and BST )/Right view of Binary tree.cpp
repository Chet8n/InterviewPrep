/**

Right view of Binary tree
Problem Description

Given a binary tree of integers denoted by root A. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree is a set of nodes visible when the tree is visited from Right side.



Problem Constraints
1 <= Number of nodes in binary tree <= 100000

0 <= node values <= 10^9



Input Format
First and only argument is head of the binary tree A.



Output Format
Return an array, representing the right view of the binary tree.



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

 [1, 3, 7, 8]
Output 2:

 [1, 3, 4, 5]


Example Explanation
Explanation 1:

Right view is described.
Explanation 2:

Right view is described.


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

    map<int, int> m;
    queue<pair<TreeNode*, int>> q;
    q.push({a, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int index = cur.second;
        TreeNode *t = cur.first;
        m[index] = t->val;
        if (t->left) {
            q.push({t->left, index + 1});
        }

        if (t->right) {
            q.push({t->right, index + 1});
        }
    }

    for (auto x : m) {
        ans.push_back(x.second);
    }

    return ans;

}

