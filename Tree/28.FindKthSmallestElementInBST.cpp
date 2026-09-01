// 230. Kth Smallest Element in a BST

// // Given the root of a binary search tree, 
// and an integer k, return the kth smallest value (1-indexed)
//   of all the values of the nodes in the tree.

// leetcode link -->>  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// 😂😂 brute force solution 
class Solution {
public:
    void put(TreeNode* root,vector<int> &ans){
        if(!root) return ;
        ans.push_back(root->val);
        put(root->left,ans);
        put(root->right,ans);
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        put(root,ans);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};
// better solution
// ♥️♥️♥️ use morris traversal to findd optimal solution 
class Solution {
public:
    int find(TreeNode* root,int& k,int & ans){
        if(!root) return 0;
        find(root->left,k,ans);
        k--;
        if(k==0) {
            ans = root->val; 
        }
        find(root->right,k,ans);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ans = 0;
        ans = find(root,k,ans);
        return ans;
    }
};

