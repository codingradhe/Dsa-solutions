// Given a root binary search tree and an integer x , find the Ceil of x in the tree.

// Ceil(x) is a number that is either equal to x or is immediately greater than x. If Ceil could not be found, return -1.
// gfg link -->>https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ans = -1;
        if(!root) return -1;
        while(root){
            int t = root->data;
            if(t == x) return t;
            else if(t > x) ans = t;
            if(t > x) root = root->left;
            else root = root->right;
        }
        return ans;
        
    }
};
