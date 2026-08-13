// leetcode link -->>https://leetcode.com/problems/time-needed-to-buy-tickets/?envType=problem-list-v2&envId=queue

class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int n =  v.size();
        queue<pair<int,int>>q;
        for(int i =0;i < n;i++){
            if(i == k) q.push({v[i],-1});
            else q.push({v[i],0});
        }
        int ans = 0;
        while(!q.empty()){
            q.front().first--;
            ans++;
            if(q.front().first == 0 && q.front().second == -1) return ans;
            if(q.front().first == 0) q.pop();
            else{
                pair<int,int>p = q.front();
                q.pop();
                q.push(p);
            }
        }
        return ans;
    }
};
