// leetcode link of this problem -->https://leetcode.com/problems/root-equals-sum-of-children/
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        if(root->left&&root->right){
            if(root->val != (root->left->val+root->right->val)) return false;
        }
        else if(root->left||root->right){
            if(root->left){
                if(root->val != root->left->val) return false;
            }
            if(root->right){
                if(root->val != root->right->val) return false;
            }
        }
        if(!checkTree(root->left)) return false;
        if(!checkTree(root->right)) return false;
        return true;
    }
};
