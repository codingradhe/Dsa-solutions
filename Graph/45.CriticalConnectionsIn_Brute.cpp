// 1192. Critical Connections in a Network
// Hard
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server 
//   connections forming a network where connections[i] = [ai, bi] represents a connection 
// between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

 class Solution {
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, int node1 ,int node2){
        vis[node] = 1;
        for(auto it: adj[node]){
            if((it == node1 && node == node2) || (it == node2 && node == node1)) continue;
            if(!vis[it])   dfs(it,adj,vis,node1,node2);
        }
        return ;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>ans;
        for(auto it : connections){
            int node1 = it[0];
            int node2 = it[1];
            vector<int>vis(n,0);
            dfs(0,adj,vis,node1,node2);
            if(count(vis.begin(),vis.end(), 1) != n) ans.push_back({node1,node2});
        }
        return ans;
    }
};
