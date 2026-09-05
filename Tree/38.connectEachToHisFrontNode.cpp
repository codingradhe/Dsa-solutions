// 116. Populating Next Right Pointers in Each Node
// Medium
// You are given a perfect binary tree where all leaves
// are on the same level, and every parent has two children
//   . The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right
// node. If there is no next right node, the next pointer 
// should be set to NULL.

// Initially, all next pointers are set to NULL.
// leetcode link -->>  https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
  class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* pre = nullptr;
            for(int i = 0;i < size;i++){
                Node* node = q.front();
                if(pre){
                    pre->next = node;
                    pre = node;
                }
                else pre = node;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return root;
    }
};
