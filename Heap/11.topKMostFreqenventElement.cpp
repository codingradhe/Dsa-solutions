// 347. Top K Frequent Elements
// Medium
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        map<int,int>mp;
        for(int i = 0;i < v.size();i++){
            mp[v[i]]++;
        }
        for(auto it:mp){
            int freq = it.second;
            int val = it.first;
            q.push({freq,val});
            if(q.size() > k) q.pop();
        }
        v.clear();
        while(!q.empty()){
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};
