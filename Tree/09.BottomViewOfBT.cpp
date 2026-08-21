// gfg link of this problem --> https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// use level order traversal in using queue and map
class Solution {
  public:
    vector<int> bottomView(Node* root) {
        vector<int>ans;
        if(!root) return ans;    
        queue<pair<int,Node*>>q;
        map<int,int>mp;
        q.push({0,root});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.first;
            Node* node = t.second;
            mp[x] = node->data;
            if(node->left){
                q.push({x-1,node->left});
            }
            if(node->right){
                q.push({x+1,node->right});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
