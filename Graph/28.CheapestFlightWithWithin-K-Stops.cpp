// 787. Cheapest Flights Within K Stops
// Medium
// There are n cities connected by some number of flights. You are given an array flights 
// where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city
// fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from 
// src to dst with at most k stops. If there is no such route, return -1.


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<pair<int,int>>>adj(n);
        int m = flights.size();
        for(int i = 0; i < m; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>ans(n,1e9);
        int cnt = 0;
        int result = INT_MAX;
        pq.push({-1,{0,src}});
        while(!pq.empty()){
            auto ptr =  pq.top();
            pq.pop();
            int stop = ptr.first;
            int price = ptr.second.first;
            int node = ptr.second.second;
            if(stop > k ) continue;
            if(node == dst) result = min(result,price);
            for(auto it : adj[node]){
                int adnode = it.first;
                int adwt = it.second;
                if(price + adwt < ans[adnode]){
                    ans[adnode] = price + adwt;
                    pq.push({stop + 1 ,{price + adwt,adnode}});
                }
            }
        }
        if(result == INT_MAX) return -1;
        return result;
    }
};
