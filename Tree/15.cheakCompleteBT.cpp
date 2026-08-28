class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool nullFound = false;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                nullFound = true;
            }
            else {
                if (nullFound)
                    return false;

                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return true;
    }
};
