/**

2-Sum Binary Tree
Problem Description

Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

Return 1 to denote that two such nodes exist. Return 0, otherwise.



Problem Constraints
1 <= size of tree <= 100000

1 <= B <= 109



Input Format
First argument is the head of the tree A.

Second argument is the integer B.



Output Format
Return 1 if such a pair can be found, 0 otherwise.



Example Input
Input 1:

         10
         / \
        9   20

B = 19
Input 2:

 
          10
         / \
        9   20

B = 40


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 10 + 9 = 19. Hence 1 is returned.
Explanation 2:

 No such pair exists.

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

// TC : o(nlogn) [can reduce to o(n) using unordered map]
// SC : o(n);

bool go(TreeNode *a, int b, map<int, int> &m) {
    if (a == NULL) {
        return false;
    }


    int now = a->val;
    int need = b - now;
    if (m[need]) {
        return true;
    }
    m[now] = 1;

    return (go(a->left, b, m) or go(a->right, b, m));
}

int Solution::t2Sum(TreeNode* a, int b) {

    map<int, int> m;
    if (a == NULL) {
        return 0;
    }

    bool ok = go(a, b, m);

    return (ok ? 1 : 0);
}

/**

- time complexity : o(n);
- space complexity : o(h) where h = height of the tree

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
int Solution::t2Sum(TreeNode* a, int b) {

    TreeNode *p1 = a;
    TreeNode *p2 = a;
    stack<TreeNode*> left, right;
    while (p1) {
        left.push(p1);
        p1 = p1->left;
    }

    while (p2) {
        right.push(p2);
        p2 = p2->right;
    }

    // now p1 is at smallest value in the tree
    // and p2 is at largest value in the tree
    // now use 2 pointer how you use in an array problem
    
    p1 = left.top();
    p2 = right.top();

    while (p1->val < p2->val) {
        int cur = p1->val + p2->val;
        if (cur == b) {
            return 1;
        }

        if (cur < b) {
            p1 = left.top()->right;
            left.pop();
            while (p1) {
                left.push(p1);
                p1 = p1->left;
            }
        } else {
            p2 = right.top()->left;
            right.pop();
            while (p2) {
                right.push(p2);
                p2 = p2->right;
            }
        }
        
        p1 = left.top();
        p2 = right.top();
    }

    return 0;
}

