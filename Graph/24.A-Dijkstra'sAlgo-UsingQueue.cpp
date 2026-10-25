// 109. Dijkstra's algorithm
// Given a weighted, undirected graph of V vertices, numbered from
// 0 to V-1, and an 2D vector/array which represents the edges:

// Each entry in edges[i] is of the form [u, v, weight], where:

// u, v → represents the vertex having undirected edge between them
// weight → the weight of the edge between u and v
// Given a source node S. Find the shortest distance of all the vertex 
// from the source vertex S. Return a list of integers denoting shortest
// distance between each node and source vertex S. If a vertex is not 
// reachable from source then its distance will be 109.
class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edg, int S) {
        int n = V;
        vector<vector<pair<int,int>>>adj(n);
        vector<int>ans(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,S});
        for(auto it:edg){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        ans[S] = 0;
        while(!q.empty()){
            auto ptr =  q.top();
            q.pop();
            int dist = ptr.first;
            int node = ptr.second;
            for(auto it : adj[node]){
                int adnode = it.first;
                int adwt = it.second;
                if(dist + adwt < ans[adnode]){
                    ans[adnode] = dist + adwt;
                    q.push({dist + adwt ,adnode});
                }
            }
        }
        return ans;
    }
};
