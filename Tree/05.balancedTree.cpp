class Solution {
public:
    int giveLen(TreeNode* root){
        if(!root) return 0;
        int ll = giveLen(root->left);
        int rl = giveLen(root->right);
        if(ll==-1||rl==-1) return -1;
        if(abs(ll-rl)>1) return -1;
        return max(ll,rl)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(giveLen(root) == -1) return false;
        return true;
    }
};
