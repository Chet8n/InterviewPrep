/**

Balanced Binary Tree
Problem Description

Given a root of binary tree A, determine if it is height-balanced.

A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the root of the tree A.



Output Format
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.



Example Input
Input 1:

    1
   / \
  2   3
Input 2:


       1
      /
     2
    /
   3


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

It is a complete binary tree.
Explanation 2:

Because for the root node, left subtree has depth 2 and right subtree has depth 0.
Difference = 2 > 1.


**/

struct info {
    int height;
    bool isBalanced;
    info(): height(0), isBalanced(true) {}
    info(int x, bool y) : height(x), isBalanced(y) {
    }
};

info go(TreeNode *a) {

    if (a == NULL) {
        info here(0, true);
        return here;
    }

    info l = go(a->left);
    info r = go(a->right);

    info res;
    res.height = 1 + max(l.height, r.height);
    res.isBalanced = ((abs(l.height - r.height) <= 1) and l.isBalanced and r.isBalanced);

    return res;
}

int Solution::isBalanced(TreeNode* a) {

    info result = go(a);
    bool ok = result.isBalanced;

    return (ok ? 1 : 0);
}
