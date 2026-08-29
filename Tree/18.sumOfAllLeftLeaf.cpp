// leetcode link of this problem ->>https://leetcode.com/problems/sum-of-left-leaves/?envType=problem-list-v2&envId=tree
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        if(!root->left&&!root->right) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* t = q.front().first;
            int x = q.front().second;
            q.pop();
            if(!t->left&&!t->right&&x == 1){
                ans += t->val;
            }
            if(t->left){
                q.push({t->left,1});
            }
            if(t->right){
                q.push({t->right,0});
            }
        }
        return ans;
    }
};
