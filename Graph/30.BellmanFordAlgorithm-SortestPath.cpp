// 118. Bellman ford algorithm
// Given a weighted and directed graph of V vertices and E edges.
//   An edge is represented as [ai, bi, wi], meaning there is a directed edge 
// from ai to bi having weight wi. Find the shortest distance of all the vertices 
// from the source vertex S. If a vertex can't be reached from the S then mark the distance as 109.

// If the graph contains a negative cycle then return -1 in a list.

class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edg, int S) {
        int n = edg.size();
        vector<int>dist(V,1e9);
        dist[S] = 0;
        for(int i = 0; i <  V - 1; i ++){
            for(int j = 0; j < n; j++){
                int u = edg[j][0];
                int v = edg[j][1];
                int wt = edg[j][2];
                if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;  
                }
            }
        }
        for(int j = 0; j < n; j++){
            int u = edg[j][0];
            int v = edg[j][1];
            int wt = edg[j][2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                return {-1};  
            }
        }
        return dist;

	}
};
