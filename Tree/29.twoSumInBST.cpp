// 653. Two Sum IV - Input is a BST
// Given the root of a binary search tree and
// an integer k, return true if there exist 
// two elements in the BST such that their 
// sum is equal to k, or false otherwise.
// leetcode link -->>   https://leetcode.com/problems/two-sum-iv-input-is-a-bst/?envType=problem-list-v2&envId=tree
  class Solution {
public:
    bool find(TreeNode* root, int& k,set<int>& st){
        if(!root) return false;
        if(st.find(k - root->val) != st.end()) return true;
        st.insert(root->val);
        if(find(root->left,k,st)) return true;
        if(find(root->right,k,st)) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return true;
        set<int>st;
        bool ans = find(root,k,st);
        return ans;
    }
};
