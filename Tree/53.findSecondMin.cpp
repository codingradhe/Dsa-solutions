// 671. Second Minimum Node In a Binary Tree
// Easy
// Given a non-empty special binary tree consisting
// of nodes with the non-negative value, where
//   each node in this tree has exactly two or
// zero sub-node. If the node has two sub-nodes
//   , then this node's value is the smaller value
// among its two sub-nodes. More formally, the property
// root.val = min(root.left.val, root.right.val
// )
//   always holds.

// Given such a binary tree, you need to output the
// second minimum value in the set made of all
// the nodes' value in the whole tree.

// If no such second minimum value exists, 
// output -1 instead.
//   https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/?envType=problem-list-v2&envId=tree
//♥️♥️♥️♥️ always consider interger overflow
class Solution {
public:
    void findmin(TreeNode* root,long long& firstmin,long long&secondmin){
        if(!root) return;
        if(root->val < firstmin){
            long long first = firstmin;
            firstmin = root->val;
            secondmin = first;
        }
        else if(root->val >firstmin && root->val <secondmin){
            secondmin = root->val;
        }
        findmin(root->left,firstmin,secondmin);
        findmin(root->right,firstmin,secondmin);
        return ;
    }
    int findSecondMinimumValue(TreeNode* root) {
        long long firstmin = LLONG_MAX;
        long long secondmin = LLONG_MAX;
        findmin(root,firstmin,secondmin);
        if(secondmin == LLONG_MAX) return -1;
        static_cast<int>(secondmin);
        return secondmin;
    }
};
