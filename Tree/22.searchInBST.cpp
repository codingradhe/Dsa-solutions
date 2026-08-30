 // You are given the root of a binary search tree (BST) and an integer val
 // Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
// leetcode link of this problem -->https://leetcode.com/problems/search-in-a-binary-search-tree/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        while(root){
            int t = root->val;
            if(t == val) return root;
            else if(t < val) root = root->right;
            else root= root->left;
        }
        return nullptr;
    }
};
