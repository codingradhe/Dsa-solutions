// brute force solution of this problem
//leetcode link of this problem -->>https://leetcode.com/problems/diameter-of-binary-tree/ 
class Solution {
public:
    int maxDepth(TreeNode* root,int ans) {
        if(!root) return 0;
        int ll = maxDepth(root->left,ans);
        int rl = maxDepth(root->right,ans);
        ans = max(ans,ll+rl+1);
        return 1+max(ll,rl);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int hight = maxDepth(root,ans);
        return ans;
    }
};
