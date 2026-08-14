// leetcode link -->https://leetcode.com/problems/binary-tree-inorder-traversal/?envType=problem-list-v2&envId=tree
class Solution {
public:
    vector<int>inorder(TreeNode* root,vector<int>&ans){
        if(root == nullptr) { 
            return ans;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>ans;
        ans = inorder(root,ans);
        return ans;
    }
};
// you have can use other solution using stack wiht O(n) time complexity
