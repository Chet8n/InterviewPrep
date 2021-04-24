/**

Least Common Ancestor
Problem Description

Find the lowest common ancestor in an unordered binary tree A given two values B and C in the tree.

Lowest common ancestor : the lowest common ancestor (LCA) of two nodes and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.



Problem Constraints
1 <= size of tree <= 100000

1 <= B, C <= 109



Input Format
First argument is head of tree A.

Second argument is integer B.

Third argument is integer C.



Output Format
Return the LCA.



Example Input
Input 1:


      1
     /  \
    2    3
B = 2
C = 3
Input 2:

      1
     /  \
    2    3
   / \
  4   5
B = 4
C = 5


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 LCA is 1.
Explanation 2:

 LCA is 2.



**/

bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if ((root->left && find(root->left, val)) ||
            (root->right && find(root->right, val)))
        return true;
    return false;
}

TreeNode* LCA(TreeNode* root, int val1, int val2)
{
    if (!root || root->val == val1 || root->val == val2)
        return root;

    auto L = LCA(root->left, val1, val2);
    auto R = LCA(root->right, val1, val2);

    if (L && R)
        return root;
    return L ? L : R;
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    if (!find(A, val1) || !find(A, val2))
        return -1;
    auto ancestor = LCA(A, val1, val2);
    if (ancestor)
        return ancestor->val;
    return -1;
}
