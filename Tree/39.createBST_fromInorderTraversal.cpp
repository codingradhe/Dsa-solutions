// 1008. Construct Binary Search Tree from Preorder 
// Traversal
// Medium

// Given an array of integers preorder, which 
//   represents the preorder traversal of a BST 
// (i.e., binary search tree), construct the tree 
// and return its root.

// It is guaranteed that there is always possible to
// find a binary search tree with the given requirements 
// for the given test cases.

// A binary search tree is a binary tree where for every 
// node, any descendant of Node.left has a value strictly
// less than Node.val, and any descendant of Node.right has
// a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the 
// value of the node first, then traverses Node.left, 
//   then traverses Node.right.
 // leetcode link -->>  https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
  class Solution {
public:
    TreeNode* makebst(vector<int>& arr,int low,int high){
        if(low > high)  return nullptr;
        TreeNode* root = new TreeNode(arr[low]);
        int mid ;
        if(low < high){
            mid = low + 1;
            while(mid <= high&&arr[low] > arr[mid]) mid++;
        }
        else {
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        root->left = makebst(arr,low + 1,mid - 1);
        root->right = makebst(arr,mid,high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        if(arr.empty()) return nullptr;
        TreeNode* root = makebst(arr,0,arr.size()-1);
        return root;
    }
};
