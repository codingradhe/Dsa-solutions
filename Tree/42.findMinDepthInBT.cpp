// 111. Minimum Depth of Binary Tree
// Easy
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along
// the shortest path from the root node down to the
// nearest leaf node.
// Note: A leaf is a node with no children.
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 2
// Example 2:
// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5
/// leetcode lin -->>  https://leetcode.com/problems/minimum-depth-of-binary-tree/?envType=problem-list-v2&envId=tree
  class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = 0;
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int size = q.size();
            int x = q.front().second;
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front().first;
                q.pop();
                if(!node->left&&!node->right) return x;
                if(node->left) q.push({node->left,x+1});
                if(node->right) q.push({node->right,x+1});
            }
        }
        return ans;
    }
};
