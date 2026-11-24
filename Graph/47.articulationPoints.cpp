// Articulation Point
// Solved
// Difficulty: Hard
// Given an undirected graph with V vertices.The graph is represented as a 2D array
// edges[][], where each element edges[i] = [u, v] indicates an undirected edge between
// vertices u and v. Return all the articulation points (or cut vertices) in the graph. An 
//   articulation point is a vertex whose removal, along with all its connected edges, increases
//   the number of connected components in the graph. 

// The given graph may be disconnected, i.e., it may consist of more than one connected component. 
// If no such point exists, return {-1}.

class Solution {
  private:
    int time = 0;
    void dfs(int node, int parent,vector<int>&vis,vector<int>&low,
    vector<int> &tin,vector<int>&marks,vector<vector<int>>&adj){
        vis[node] = 1;
        low[node] = tin[node] = time;
        time++;
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,low,tin,marks,adj);
                low[node]  = min(low[it], low[node]);
                if(low[it] >= tin[node] && parent != -1){
                    marks[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child > 1 && parent == -1){
            marks[node] = 1; 
        }
        return;
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edg) {
        int n = V;
        vector<vector<int>>adj(n);
        for(auto it : edg){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);
        vector<int>marks(n , 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]) dfs(i, -1, vis,low,tin,marks,adj);
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(marks[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};


