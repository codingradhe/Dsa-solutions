// leetcode link of this problem -->>https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;    
        queue<pair<int,TreeNode*>>q;
        map<int,int>mp;
        q.push({0,root});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int y = t.first;
            TreeNode* node = t.second;
            mp[y] = node->val;
            if(node->left){
                q.push({y+1,node->left});
            }
            if(node->right){
                q.push({y+1,node->right});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
