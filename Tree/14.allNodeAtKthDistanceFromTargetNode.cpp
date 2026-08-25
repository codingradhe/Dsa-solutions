//leetcode link of this problem -->> https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    void mapparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        if(!root) return;
        TreeNode* curr = root;
        if(root->left){
            parent[root->left] = curr;
            mapparent(root->left,parent);
        }
        if(root->right){
            parent[root->right] = curr;
            mapparent(root->right,parent);
        }
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>>q;
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>visited;
        mapparent(root,parent);
        q.push({target,0});
        visited[target] = true;
        while(!q.empty()){
            int size = q.size();
            int x = q.front().second;
            if(x==k) break;
            for(int i = 0;i < size; i++){
                TreeNode* t = q.front().first;
                int x = q.front().second;
                q.pop();
                if(t->left&&!visited[t->left]){
                    q.push({t->left,x+1});
                    visited[t->left] = true;
                }
                if(t->right&&!visited[t->right]){
                    visited[t->right] = true;
                    q.push({t->right,x+1});
                }
                if(parent.find(t) != parent.end()&&!visited[parent[t]]){
                    visited[parent[t]] = true;
                    q.push({parent[t],x+1});
                }
            }
        }
        int size = q.size();
        for(int i =0;i < size;i++){
            ans.push_back(q.front().first->val);
            q.pop();
        }
        return ans;
    }
};
