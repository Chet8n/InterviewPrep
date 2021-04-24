/**

Equal Tree Partition
Problem Description

Given a binary tree A. Check whether it is possible to partition the tree to two trees which have equal sum of values after removing exactly one edge on the original tree.



Problem Constraints
1 <= size of tree <= 100000

-109 <= value of node <= 109



Input Format
First and only argument is head of tree A.



Output Format
Return 1 if the tree can be partitioned into two trees of equal sum else return 0.



Example Input
Input 1:


                5
               /  \
              3    7
             / \  / \
            4  6  5  6
Input 2:


                1
               / \
              2   10
                  / \
                 20  2


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Remove edge between 5(root node) and 7:
        Tree 1 =                                               Tree 2 =
                        5                                                     7
                       /                                                     / \
                      3                                                     5   6
                     / \
                    4   6
        Sum of Tree 1 = Sum of Tree 2 = 18
Explanation 2:

 The given Tree cannot be partitioned.

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

using ll = long long int;

ll getTotal(TreeNode *a, stack<ll> &s) {

    if (a == NULL) {
        return 0;
    }

    ll leftsum = getTotal(a->left, s);
    ll rightsum = getTotal(a->right, s);

    ll here = a->val + leftsum + rightsum;
    s.push(here);

    return here;
}

int Solution::solve(TreeNode* a) {

    stack<ll> s;
    ll tot = getTotal(a, s);
    bool ok = false;


    s.pop();


    while (!s.empty()) {

        ll x = s.top();
        s.pop();
        ll y = tot - x;
        if (x == y) {
            ok = true;
            break;
        }
    }

    return (ok ? 1 : 0);
}
