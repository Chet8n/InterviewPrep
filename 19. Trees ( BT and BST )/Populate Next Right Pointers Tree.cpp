/**

Populate Next Right Pointers Tree
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.
Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

**/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

TreeLinkNode* getNext(TreeLinkNode *a) {

    a = a->next;
    while (a) {
        if (a->left) {
            return a->left;
        }

        if (a->right) {
            return a->right;
        }

        a = a->next;
    }

    return a;
}


void Solution::connect(TreeLinkNode* a) {

    if (a == NULL) {
        return;
    }

    // this is vertical node to travel successive levels
    TreeLinkNode *v = a;

    // this is horizontal node to travel all nodes of same level
    TreeLinkNode *h;

    while (v) {

        h = v;
        while (h) {
            if (h->left) {
                h->left->next = h->right ? h->right : getNext(h);
            }

            if (h->right) {
                h->right->next = getNext(h);
            }

            h = h->next;
        }

        if (v->left) {
            v = v->left;
        } else if (v->right) {
            v = v->right;
        } else {
            v = getNext(v);
        }
    }
}


