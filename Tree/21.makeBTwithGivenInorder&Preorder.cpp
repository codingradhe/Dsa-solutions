// leetcode link of this problem -->> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    TreeNode* buildtree(vector<int>& preorder,int prest,int preend, vector<int>& inorder,int inst,int inend,map<int,int>& mp){
        if(prest>preend||inst>inend) return nullptr;
        TreeNode* root = new TreeNode(preorder[prest]);
        int inroot = mp[root->val];
        int numsleft = inroot -inst;
        root->left = buildtree(preorder,prest+1,prest+numsleft,inorder,inst,inroot-1,mp);
        root->right = buildtree(preorder,prest+numsleft+1,preend,inorder,inroot+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i = 0; i < inorder.size();i++ ){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildtree(preorder,0,preorder.size()-1, inorder,0,inorder.size()-1,mp);
        return root;
    }
};
