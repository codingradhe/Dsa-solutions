//leetcode link of this problem -->> https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    void flat(TreeNode* root,TreeNode*& newroot){
        if(!root) return ;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        newroot->right = root;
        newroot = newroot->right;
        newroot->left = nullptr;
        flat(left,newroot);
        flat(right,newroot);
        return ;
    }
    void flatten(TreeNode* root) {
        TreeNode* newroot = new TreeNode(-1);
        newroot->left = NULL;
        if(!root) return ;
        flat(root,newroot);
        root = newroot->right;
        return ;
    }
};
