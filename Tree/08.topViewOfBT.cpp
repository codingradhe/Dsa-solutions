// gfg link of this problem -->>https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
//♥️♥️♥️ use map datastruture and level order traversal with queue
class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        vector<int>ans;
        if(!root) return ans;
        q.push({root,0});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.second;
            Node* p = t.first;
            if(mp.find(x) == mp.end()){
                mp[x] = p->data;
            }
            if(p->left) q.push({p->left,x-1});
            if(p->right) q.push({p->right,x+1});
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
