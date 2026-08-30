// leetcode link of this problem -->> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/?envType=problem-list-v2&envId=tree
class Solution {
public:
    TreeNode* buildtree(vector<int>& inorder,int inst,int inend, vector<int>& postorder,int postst,int postend,map<int,int>& inmap){
        if(inst>inend||postst>postend) return nullptr;
        TreeNode* root = new TreeNode(postorder[postend]);
        int st = inmap[root->val];
        int nums = st - inst;
        root->left = buildtree(inorder,inst,st-1,postorder,postst,postst+nums-1,inmap);
        root->right = buildtree(inorder,st+1,inend,postorder,postst+nums,postend-1,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inmap;
        for(int i = 0;i < inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        TreeNode* root = buildtree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inmap);
        return root;
    }
};
