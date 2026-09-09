// 99. Recover Binary Search Tree
// Medium
// Topics
// premium lock icon
// Companies
// You are given the root of a binary search tree (BST)
//   , where the values of exactly two nodes of the tree 
// were swapped by mistake. Recover the tree without changing its structure.
    
// leetcode link ->>  https://leetcode.com/problems/recover-binary-search-tree/description/?utm_source=chatgpt.com

  class Solution {
public:
    void findvec(TreeNode* root, TreeNode*& first,
                 TreeNode*& second, TreeNode*& pre) {
        
        if (!root) return;

        findvec(root->left, first, second, pre);

        if (pre && pre->val > root->val) {
            if (!first) {
                first = pre;
            }
            second = root;
        }

        pre = root;

        findvec(root->right, first, second, pre);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* pre = nullptr;

        findvec(root, first, second, pre);

        swap(first->val, second->val);
    }
};
