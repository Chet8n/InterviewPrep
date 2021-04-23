/**

Check if given Preorder, Inorder and Postorder traversals are of same tree
Given 3 array of integers A, B and C.

A represents preorder traversal of a binary tree.

B represents inorder traversal of a binary tree.

C represents postorder traversal of a binary tree.

Check whether these tree traversals are of the same tree or not. If they are of same tree return 1 else return 0.


Input Format

The arguments given are integer arrays A, B, and C.
Output Format

Return 1 if they are of same tree else return 0.
Constraints

1 <= length of the array <= 1000
all arrays are of same length
1 <= A[i], B[i], C[i] <= 10^9
For Example

Input 1:
    A = [1, 2, 4, 5, 3]
    B = [4, 2, 5, 1, 3]
    C = [4, 5, 2, 3, 1]
Output 1:
    1

Input 2:
    A = [1, 5, 4, 2, 3]
    B = [4, 2, 5, 1, 3]
    C = [4, 1, 2, 3, 5]

Output 2:
    0


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

int search(vector<int> &in, int instart, int inend, int data) {

    int index = -1;
    for (int i = instart; i <= inend; i++) {
        if (in[i] == data) {
            index = i;
            break;
        }
    }

    return index;
}

void go(vector<int> &pre, vector<int> &in, vector<int> &post, int instart, int inend, int &preIndex, int &postIndex, bool &ok) {

    if (instart > inend) {
        return;
    }

    int index = search(in, instart, inend, pre[preIndex++]);

    if (index == -1) {
        ok = false;
        return;
    }

    go(pre, in, post, instart, index - 1, preIndex, postIndex, ok);
    go(pre, in, post, index + 1, inend, preIndex, postIndex, ok);

    if (in[index] != post[postIndex++]) {
        ok = false;
    }


}

int Solution::solve(vector<int> &pre, vector<int> &in, vector<int> &post) {

    int n = pre.size();

    int preIndex = 0;
    int postIndex = 0;

    /**
    
    - basic approach will be to construct tree using inorder and preorder
      tree traversal
    - and now get the post order traversal and check if the given postorder
      traversal is same or not
    - TC : o(n*n), SC : o(n)

    
    **/

    /**

    Optimized

    - similar to building a tree from given preorder and inorder traversals
    - but instead of building try to store post order traversal
    - again instead of storing check if it matches with given post order traversal
    - TC : o(n*n), SC : o(h) [recurssion stack]

    **/
    bool ok = true;
    go(pre, in, post, 0, n - 1, preIndex, postIndex, ok);

    return ok;

}




int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{

    int n = A.size();

    int preIndex = 0;
    int postIndex = 0;
    bool res = true;

    printPost(B, A, C, 0, n - 1, preIndex, postIndex, res);

    return res;

}
