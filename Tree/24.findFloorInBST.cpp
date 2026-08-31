// Given the root of a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.

// Note: If no such node value exists that is smaller than k, then return -1.

 // gfg link-->> https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        if(!root) return -1;
        while(root){
            int t = root->data;
            if(t == k) return t;
            else if(t < k) ans = t;
            if(k > t) root = root->right;
            else root = root->left;
        }
        return ans;
    }
};
