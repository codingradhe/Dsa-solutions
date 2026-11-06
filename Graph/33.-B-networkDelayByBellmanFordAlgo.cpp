// 743. Network Delay Time
// Solved
// Medium
// You are given a network of n nodes, labeled from 1 to n. You are also given
// times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
// where ui is the source node, vi is the target node, and wi is the time it
// takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes
// for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edg, int n, int k) {
        int m = edg.size(); // number of edges to itrate all 
        vector<int>dist(n + 1,1e9);
        dist[k] = 0;
        for(int i = 0; i <  n; i++){ // we need max  n - 1 iteration to find result
            for(int j = 0; j < m; j++){
                int u = edg[j][0];
                int v = edg[j][1];
                int wt = edg[j][2];
                if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;  
                }
            }
        }
        int ans = 0;
        for(int j = 1; j < n + 1; j++){ // start form 1 because nodes are stated from 1 ,(we have additional node 0 at distance infinity
            if(dist[j] == 1e9) return - 1;// unreachable node
            ans = max( ans , dist[j]);
        }
        return ans;
    }
};
