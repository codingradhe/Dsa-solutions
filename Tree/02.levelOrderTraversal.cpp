// leetcode link of this problem -->>https://leetcode.com/problems/binary-tree-level-order-traversal/?utm_source=chatgpt.com
// ♥️♥️ use queue to store node at perticul level
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root == nullptr) return ans;
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i = 0; i < size;i++){
                TreeNode* a = q.front();
                q.pop();
                level.push_back(a->val);
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
