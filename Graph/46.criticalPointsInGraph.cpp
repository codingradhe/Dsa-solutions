// 1192. Critical Connections in a Network
// Solved
// Hard

// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server 
//   connections forming a network where connections[i] = [ai, bi] represents a connection between
// servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

 class Solution {
    int time = 1;
private:
    void dfs(int node,int parent,vector<int>&tin, vector<int>&low , 
    vector<int>&vis,vector<vector<int>>&adj,
    vector<vector<int>>&bridges){
        vis[node] = 1;
        tin[node]  =  low[node] = time;
        time++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,tin,low,vis,adj,bridges);
                low[node] = min(low[it], low[node]);
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                } 
            }
            else {
                low[node] = min(low[it],low[node]); 
            }
        }
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
        vector<vector<int>>bridges;
        vector<int>tin(n,0);
        vector<int>low(n,0);
        vector<int>vis(n,0);
        dfs(0,-1,tin,low,vis,adj,bridges);
        return bridges;
    }
}; 
