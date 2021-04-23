vector<int> Solution::postorderTraversal(TreeNode* a) {

    vector<int> ans;

    if (a == NULL) {
        return ans;
    }

    TreeNode *cur = a;

    stack<TreeNode*> s;
    s.push(a);

    while (!s.empty()) {

        TreeNode *temp = s.top();
        s.pop();
        ans.push_back(temp->val);

        if (temp->left) {
            s.push(temp->left);
        }
        if (temp->right) {
            s.push(temp->right);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;

}
