/**

TOP VIEW
Problem Description

Given a binary tree of integers denoted by root A. Return an array of integers representing the top view of the Binary tree.

Right view of a Binary Tree is a set of nodes visible when the tree is visited from top.

Return the nodes in any order.



Problem Constraints
1 <= Number of nodes in binary tree <= 100000

0 <= node values <= 10^9



Input Format
First and only argument is head of the binary tree A.



Output Format
Return an array, representing the top view of the binary tree.



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

 [1, 2, 4, 8, 3, 7]
Output 2:

 [1, 2, 3]


Example Explanation
Explanation 1:

Top view is described.
Explanation 2:

Top view is described.

**/

vector<int> Solution::solve(TreeNode* a) {

    vector<int> ans;
    if (a == NULL) {
        return ans;
    }

    map<int, int> m;
    queue<pair<TreeNode* , int>> q;
    q.push({a, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int index = cur.second;
        TreeNode *here = cur.first;
        if (m.find(index) == m.end()) {
            m[index] = here->val;
        }

        if (here->left) {
            q.push({here->left, index - 1});
        }

        if (here->right) {
            q.push({here->right, index + 1});
        }
    }

    for (auto x : m) {
        ans.push_back(x.second);
    }

    return ans;

}
