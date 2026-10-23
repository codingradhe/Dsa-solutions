// 961. Shortest path in undirected graph with unit weights
// Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D 
// Integer array edges, where there is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.

// Find the shortest path from the source to all other nodes in this graph. In this
// problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable
// from the source node, then return -1 for that vertex.

// Example 1:
// Input: n = 9, m = 10, edges = [[0,1],[0,3],[3,4],[4,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]

// Output: 0 1 2 1 2 3 3 4 4

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edg, int n,int M){
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i = 0;  i < M;i++){
            int v = edg[i][0];
            int u = edg[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>ans(n,-1);
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(!vis[node]) ans[node] = dist;
            vis[node] = 1;
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it,dist+1});
                }
            }
        }
        return ans;
    }
};
