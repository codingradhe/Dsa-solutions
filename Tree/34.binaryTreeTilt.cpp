// 563. Binary Tree Tilt
// Given the root of a binary tree, return the 
//   sum of every tree node's tilt.

// The tilt of a tree node is the absolute difference
// between the sum of all left subtree node values and
// all right subtree node values. If a node does not have
// a left child, then the sum of the left subtree node
// values is treated as 0. The rule is similar if the node
// does not have a right child.
// Example 1:
// Input: root = [1,2,3]
// Output: 1
// leetcode link -->>   https://leetcode.com/problems/binary-tree-tilt/?envType=problem-list-v2&envId=tree
  class Solution {
public:
    int tilt(TreeNode*& root,int sum,int& ans){
        if(!root) return 0;
        int lsum = tilt(root->left,sum,ans);
        int rsum   = tilt(root->right,sum,ans);
        sum += root->val +lsum+rsum;
        ans += abs(lsum-rsum);
        return sum;
    }
    int findTilt(TreeNode* root) {
        int ans = 0,sum = 0;
        if(!root) return ans;
        sum =  tilt(root,sum,ans);
        return ans;
    }
};
