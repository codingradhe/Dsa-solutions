// 965. Univalued Binary Tree
// Easy
// A binary tree is uni-valued if every node in the tree has the same value.

// Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
// leetcode link -->>   https://leetcode.com/problems/univalued-binary-tree/?envType=problem-list-v2&envId=tree
class Solution {
public:
    set<int>st;
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        st.insert(root->val);
        if(st.size() > 1) return false;
        if(!isUnivalTree(root->left)) return false;
        if(!isUnivalTree(root->right)) return false;
        return true;
    }
};
