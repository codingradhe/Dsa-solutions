// 450. Delete Node in a BST

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.

  // leetcode link -->>https://leetcode.com/problems/delete-node-in-a-bst/
  class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(!root->left&&!root->right&&root->val == key) return nullptr;
        if(root->val == key){
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            else {
                TreeNode* newroot = root->right;
                TreeNode* left = root->left;
                TreeNode* mover = newroot;
                while(mover->left) mover = mover->left;
                mover->left = left;
                return newroot;
            }
        }
        TreeNode* curr = root;
        while(curr){
            if(curr->left && curr->left->val == key){
                TreeNode* node = curr->left;
            
                if(!node->left)
                    curr->left = node->right;
                else if(!node->right)
                    curr->left = node->left;
                else {
                    TreeNode* left = node->left;
                    TreeNode* right = node->right;
            
                    curr->left = left;
            
                    TreeNode* mover = left;
                    while(mover->right) mover = mover->right;
                    mover->right = right;
                }
                return root;
            }
            if(curr->right && curr->right->val == key){
                TreeNode* node = curr->right;
            
                if(!node->left)
                    curr->right = node->right;
                else if(!node->right)
                    curr->right = node->left;
                else {
                    TreeNode* left = node->left;
                    TreeNode* right = node->right;
            
                    curr->right = right;
            
                    TreeNode* mover = right;
                    while(mover->left)
                        mover = mover->left;
            
                    mover->left = left;
                }
            
                return root;
            }
            if(curr->val < key) curr = curr->right;
            else curr = curr->left;
        }
        return root;
    }
};
