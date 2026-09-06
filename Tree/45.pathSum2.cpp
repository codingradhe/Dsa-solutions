// 113. Path Sum II
// Medium
// Given the root of a binary tree and an integer
// targetSum, return all root-to-leaf paths where the
// sum of the node values in the path equals targetSum.
//   Each path should be returned as a list of the node
// values, not node references.
  

// A root-to-leaf path is a path starting from the
// root and ending at any leaf node. A leaf is a node
// with no children.
// leetcode link -->>   https://leetcode.com/problems/path-sum-ii/?envType=problem-list-v2&envId=tree
  class Solution {
public:
    bool isleaf(TreeNode* root){
        if(!root->left&&!root->right) return true;
        return false ;
    }
    void findsum(TreeNode* root,vector<vector<int>>& ans,vector<int>v,int target){
        if(isleaf(root)){
            if(target == root->val) {
                v.push_back(root->val);
                ans.push_back(v);
                return;
            }
            else return ;
        }
        target -= root->val;
        v.push_back(root->val);
        if(root->left) findsum(root->left,ans,v,target);
        if(root->right) findsum(root->right,ans,v,target);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>>ans;
        if(!root) return ans;
        vector<int>v;
        findsum(root,ans,v,target);
        return ans;
    }
};
