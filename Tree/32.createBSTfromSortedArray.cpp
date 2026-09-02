// 108. Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements 
// are sorted in ascending order, convert it to a
// height-balanced binary search tree.
// Example 1:
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also

// leetcode link -->> https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=problem-list-v2&envId=tree

class Solution {
public:
    TreeNode* makebst(vector<int>& v,int low,int high){
        if(low>high) return nullptr;
        int x = (low+high)/2;
        TreeNode* root = new TreeNode(v[x]);
        root->left = makebst(v,low,x-1);
        root->right = makebst(v,x+1,high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& v){
        if(v.empty()) return nullptr;
        TreeNode* root = makebst(v,0,v.size()-1);
        return root;
    }
};
