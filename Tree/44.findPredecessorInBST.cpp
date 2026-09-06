// Predecessor and Successor in BST
// Solved: 4
// Given a Binary Search Tree (BST) and an integer key,
// find the inorder predecessor and inorder successor of
// the given key.

// The inorder predecessor is the node with the largest
// value smaller than the given key.
// The inorder successor is the node with the smallest 
// value greater than the given key.
// If the predecessor or successor does not exist, return
// NULL for that position.

// Note: The key may or may not be present in the BST.

// Examples :

// Input: root = [50, 30, 70, 20, 40, 60, 80], key = 65
  
//   problem link -->>  https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
  class Solution {
  public:
    
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*>ans;
        Node* pre = nullptr;
        Node* p = root;
        Node* suc = nullptr;
        while(p){
            if(p->data <= key) p = p->right;
            else {
                suc = p;
                p = p->left;
            }
        }
        p = root;
        while(p){
            if(p->data >= key) p = p->left;
            else {
                pre = p;
                p = p->right;
            }
        }
        ans.push_back(pre);
        ans.push_back(suc);
        return ans;
    }
};
