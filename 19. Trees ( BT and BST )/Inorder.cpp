vector<int> Solution::inorderTraversal(TreeNode* a) {

    vector<int> ans;

    stack<TreeNode*> s;

    TreeNode *cur = a;

    while (cur or !s.empty()) {

        while (cur) {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();
        ans.push_back(cur->val);
        cur = cur->right;
    }

    return ans;
}
