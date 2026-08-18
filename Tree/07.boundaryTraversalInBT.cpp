
// ♥️♥️♥️concept --> left traversal + leaf traversal + right traversal
// gfg link of this problem --> https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
class Solution {
    public:
    bool isleaf(Node* root){
        if(!root->left&&!root->right) return true;
        return false;
    }
    void addleft(Node* root,vector<int>& ans){
        Node* curr = root;
        while(curr&&!isleaf(curr)){
            if(!isleaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else if(curr->right) curr = curr->right;
        }
        return;
    }
    void addleaf(Node* root,vector<int>& ans){
        if(!root) return;
        if(isleaf(root)) ans.push_back(root->data);
        addleaf(root->left,ans);
        addleaf(root->right,ans);
        return;
    }
    void addright(Node* root,vector<int>& ans){
        Node* curr = root;
        vector<int>res;
        while(curr&&!isleaf(curr)){
            if(!isleaf(curr)) res.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else if(curr->left)curr = curr->left;
        }
        for(int i =res.size()-1;i >= 0;i--){
            ans.push_back(res[i]);
        }
        return;
    }
    vector<int> boundaryTraversal(Node *root){
        vector<int>ans;
        if(!root) return ans;
        if(isleaf(root)) {
            ans.push_back(root->data);
            return ans;
        }
        ans.push_back(root->data);
        if(root->left) addleft(root->left,ans);
        addleaf(root,ans);
        if(root->right) addright(root->right,ans);
        return ans;
    }
};
