// 701. Insert into a Binary Search Tree
// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
// leetcode link -->>  https://leetcode.com/problems/insert-into-a-binary-search-tree/?utm_source=chatgpt.com
  class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if(!root) return newnode;
        TreeNode* curr = root;
        while(curr){
            int t = curr->val;
            if(curr->left && val < t && val > curr->left->val){
                TreeNode* left = curr->left;
                curr->left = newnode;
                newnode->left = left;
                return root;
            }
            else if(curr->right && val > t && val < curr->right->val){
                TreeNode* right = curr->right;
                curr->right = newnode;
                newnode->right = right;
                return root;
            }
            else if(!curr->left && val < t){
                curr->left = newnode;
                return root;
            }
            else if(!curr->right && val > t){
                curr->right = newnode;
                return root;
            }
            if(t > val) curr = curr->left;
            else curr = curr->right;
        }
        return root;
    }
};
