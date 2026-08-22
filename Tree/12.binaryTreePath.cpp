// leetcode link of this problem-->>https://leetcode.com/problems/binary-tree-paths/
class Solution {
public:
    vector<string> nodepath(TreeNode* root,vector<string>& ans,string s){
        if(!root->left&&!root->right) {
            ans.push_back(s);
            return ans;
        }
        string a = s;
        if(root->left){
            s = a+ "->" + to_string(root->left->val);
            ans = nodepath(root->left,ans,s);
        }
        if(root->right){
            s = a+ "->" + to_string(root->right->val);
            ans = nodepath(root->right,ans,s);
        }
        return ans;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s ;
        vector<string>ans;
        if(!root) return ans;
        s += to_string(root->val);
        ans = nodepath(root,ans,s);
        return ans;
    }
};
