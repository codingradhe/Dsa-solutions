// leetcode link of this problem -->>https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ll = maxDepth(root->left);
        int rl = maxDepth(root->right);
        return 1+max(ll,rl);
    }
};
