/**

Common Nodes in Two BST
Problem Description

Given two BST's A and B, return the (sum of all common nodes in both A and B) % (109 +7) .

In case there is no common node, return 0.

NOTE:

Try to do it one pass through the trees.



Problem Constraints
1 <= Number of nodes in the tree A and B <= 105

1 <= Node values <= 106



Input Format
First argument represents the root of BST A.

Second argument represents the root of BST B.



Output Format
Return an integer denoting the (sum of all common nodes in both BST's A and B) % (109 +7) .



Example Input
Input 1:

 Tree A:
    5
   / \
  2   8
   \   \
    3   15
        /
        9

 Tree B:
    7
   / \
  1  10
   \   \
    2  15
       /
      11
Input 2:

  Tree A:
    7
   / \
  1   10
   \   \
    2   15
        /
       11

 Tree B:
    7
   / \
  1  10
   \   \
    2  15
       /
      11


Example Output
Output 1:

 17
Output 2:

 46


Example Explanation
Explanation 1:

 Common Nodes are : 2, 15
 So answer is 2 + 15 = 17
Explanation 2:

 Common Nodes are : 7, 2, 1, 10, 15, 11
 So answer is 7 + 2 + 1 + 10 + 15 + 11 = 46

**/

/**

- Time complexity : o(n)
- Space complexity : o(n)

**/

void dfs(TreeNode *root, unordered_map<int, int>& m) {
    if (!root) return;
    m[root->val]++;
    dfs(root->left, m);
    dfs(root->right, m);
}
 
int Solution::solve(TreeNode* A, TreeNode* B) {
    using ll = long long int;
    ll mod = (1e9+7);
    unordered_map<int, int> m;
    dfs(A, m);
    dfs(B, m);
    ll res = 0;
    for (auto &p:m)
        if (p.second>1)
            res += p.first;
            res %= mod;
    return res;
}

/**

- Time Complexity : o(n);
- Space complexity : o(h), where h is the height of the tree!

**/

int Solution::solve(TreeNode* a, TreeNode* b) {

    using ll = long long int;
    ll mod = (1e9 + 7);

    stack<TreeNode*> frst, sec;

    TreeNode *p1 = a;
    TreeNode *p2 = b;

    ll ans = 0;

    while (1) {

        if (p1) {
            frst.push(p1);
            p1 = p1->left;
        } else if (p2) {
            sec.push(p2);
            p2 = p2->left;
        } else if (!frst.empty() and !sec.empty()) {

            p1 = frst.top();
            p2 = sec.top();

            if (p1->val == p2->val) {
                ans += p1->val;
                ans %= mod;
                frst.pop();
                sec.pop();
                p1 = p1->right;
                p2 = p2->right;

            } else if (p1->val <  p2->val) {
                frst.pop();
                p1 = p1->right;
                p2 = NULL;
            } else if (p1->val > p2->val) {
                sec.pop();
                p2 = p2->right;
                p1 = NULL;
            }
        } else {
            break;
        }
    }

    return ans;

}
