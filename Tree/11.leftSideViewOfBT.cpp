// gfg link of this problem -->>https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int>ans;
        if(!root) return ans;    
        queue<pair<int,Node*>>q;
        map<int,int>mp;
        q.push({0,root});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int y = t.first;
            Node* node = t.second;
            if(mp.find(y) == mp.end()){
                mp[y] = node->data;
            }
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
