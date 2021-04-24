/**

Binary tree to Circular Doubly Linked List
Problem Description

Given a binary tree convert it into circular doubly linked list based on the following rules:

The left and right pointers in nodes are to be used as previous and next pointers respectively in converted Circular Linked List.
The order of nodes in List must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal must be the head node of the Circular List.
NOTE: You are expected to convert the binary tree into Doubly linked list in place.



Problem Constraints
1 <= Number of nodes in tree <= 100000

1 <= Value of node <= 109



Input Format
The only argument given is the root pointer of the tree, A.



Output Format
Return the head pointer of the converted circular doubly linked list.



Example Input
Input 1:

 Serialized from input of binary tree:(where 7 denotes the number of elements in serial)
    7 20 8 -1 -1 22 -1 -1
    Binary tree is
      20
     /  \
    8    22
    8 is the left child of 20 and 22 is the right child of 20.
Input 2:

 Serialized from input of binary tree:(where 7 denotes the number of elements in serial)
    7 10 8 -1 -1 11 -1 -1
    Binary tree is
      10
     /  \
    8    11
    8 is the left child of 10 and 11 is the right child of 10.


Example Output
Output 1:

     _____________
    |             |
    8 <-> 20 <-> 22
    |_____________|
Output 2:

     _____________
    |             |
    8 <-> 10 <-> 11
    |_____________|


Example Explanation
Explanation 1:

 The inorder traversal of binary tree is: [8, 20, 22]. Return the head pointer of the circular doubly linked list.
Explanation 2:

 The inorder traversal of binary tree is: [8, 10, 11]. Return the head pointer of the circular doubly linked list.

**/

/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

TreeNode* merge(TreeNode *leftlist, TreeNode *rightlist) {

    if (leftlist == NULL) {
        return rightlist;
    }

    if (rightlist == NULL) {
        return leftlist;
    }

    TreeNode *leftlast = leftlist->left;
    TreeNode *rightlast = rightlist->left;

    leftlast->right = rightlist;
    rightlist->left = leftlast;

    rightlast->right = leftlist;
    leftlist->left = rightlast;

    return leftlist;

}

TreeNode* go(TreeNode *a) {

    if (a == NULL) {
        return NULL;
    }

    TreeNode *l = go(a->left);
    TreeNode *r = go(a->right);

    a->left = a->right = a;

    return merge(merge(l, a), r);
}

TreeNode* solve(TreeNode *a) {

    return go(a);

}

