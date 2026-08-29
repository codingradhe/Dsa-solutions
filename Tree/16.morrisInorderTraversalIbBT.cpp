// morris traversal = O(N) TC + O(1) SC

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>ans;
        if(!root) return ans;
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* pre = curr->left;
                while(pre->right&&pre->right !=curr){
                    pre = pre->right;
                }
                if(!pre->right){
                    pre->right = curr;
                    curr= curr->left;
                }
                else{
                    pre->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
