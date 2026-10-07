// 1791. Find Center of Star Graph
// Easy
// Topics
// premium lock icon
// Companies
// There is an undirected star graph consisting of n nodes labeled
// from 1 to n. A star graph is a graph where there is one center node
// and exactly n - 1 edges that connect the center node with every 
// other node.

// You are given a 2D integer array edges where each 
// edges[i] = [ui, vi] indicates that there is an edge
// between the nodes ui and vi. Return the center of the given
// star graph.
class Solution {
public:
    int findCenter(vector<vector<int>>& mat) {
        int n = mat.size() + 1;
        vector<vector<int>> adj(n);
        for(auto it:mat){
            int u = it[0],v = it[1];
            adj[v - 1].push_back(u);
            adj[u - 1].push_back(v);
        }
        int ans;
        for(int i = 0;i < n;i++){
            if(adj[i].size() == n - 1){
                ans = i + 1;
                return i + 1;
            }
        }
        return ans;
    }
};
