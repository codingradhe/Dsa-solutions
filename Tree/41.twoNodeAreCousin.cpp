// 993. Cousins in Binary Tree
// Easy
// Given the root of a binary tree with unique values
// and the values of two different nodes of the
// tree x and y, return true if the nodes corresponding to
// the values x and y in the tree are cousins,
// or false otherwise.

// Two nodes of a binary tree are cousins if 
// they have the same depth with different 
// parents.
//
// Note that in a binary tree, the root node
// is at the depth 0, and children of each depth
// k node are at the depth k + 1.
// leetcode link -->>   https://leetcode.com/problems/cousins-in-binary-tree/
  class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*,int>p1,p2;
        queue<pair<TreeNode*,pair<TreeNode*,int>>>q;
        q.push({root,{nullptr,0}});
        while(!q.empty()){
            int size = q.size();
            int level = q.front().second.second;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second.first;
                q.pop();
                if(node->val == x) p1 = {parent,level};
                if(node->val == y ) p2 = {parent,level};
                if(node->left) q.push({node->left,{node,level+1}});
                if(node->right) q.push({node->right,{node,level+1}});
            }
        }
        if(p1.first != p2.first&& p1.second == p2.second) return true;
        else return false;
    }
};
