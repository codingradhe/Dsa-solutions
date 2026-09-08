// 653. Two Sum IV - Input is a BST
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary search tree and an integer
// k, return true if there exist two elements in the BST
// such that their sum is equal to k, or false otherwise.
 // leetcode link of this problem -->> https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
  
class Solution {
public:
    set<int>st;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(st.find(root->val)!=st.end()) return true;
        st.insert(k-root->val);
        if(findTarget(root->left,k)) return true;
        if(findTarget(root->right,k)) return true;
        return false;
    }
};
