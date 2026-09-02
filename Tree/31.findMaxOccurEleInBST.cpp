// 501. Find Mode in Binary Search Tree

// Given the root of a binary search tree (BST) 
// with duplicates, return all the mode(s) 
// (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in 
// any order.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes 
// with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes 
// with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be 
// binary search trees.

  // 👋👋leetcode link -->>https://leetcode.com/problems/find-mode-in-binary-search-tree/?envType=problem-list-v2&envId=tree
// brute force solution
class Solution {
public:
    void findmode(TreeNode* root,map<int,int>& mp,int& maxfreq){
        if(!root) return ;
        mp[root->val]++;
        maxfreq = max(maxfreq,mp[root->val]);
        findmode(root->left,mp,maxfreq);
        findmode(root->right,mp,maxfreq);
        return ;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        int maxfreq = 0;
        if(!root) return ans;
        map<int,int>mp;
        findmode(root,mp,maxfreq);
        for(auto it : mp){
            if(it.second == maxfreq) ans.push_back((it.first));
        }
        return ans;
    }
};
 // ♥️♥️♥️optinal solution 
class Solution {
public:
    int maxCount = INT_MIN;
    int currCount = 0;
    TreeNode* prev = NULL;
    vector<int> ans;
    
    void inorder(TreeNode* root, bool getlist){
        if(!root) return;
        
        inorder(root->left, getlist);
        
        if(prev && prev->val==root->val)
            currCount++;
        else
            currCount=1;
        if(!getlist) maxCount = max(maxCount, currCount);
        else if(currCount==maxCount) ans.push_back(root->val);
        prev = root;
        inorder(root->right, getlist);
    }
    
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        if(!root) return ans;
        // get max list
        inorder(root, false);
        
        // Get the final list
        prev = NULL;
        currCount = 0;
        inorder(root, true);
        
        return ans;
    }
};
