// Topological Sort
// Solved
// Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E directed edges 

// represented by a 2D array edges[][], where edges[i] = [u, v] denotes a directed edge from vertex u 
// to vertex v, return a topological ordering of all the vertices.

// A topological ordering is a linear ordering of the vertices such that for every directed edge u -> v,
// vertex u appears before vertex v in the ordering.

// Note: As there are multiple Topological orders possible, you may return any of them. If your 
// returned Topological sort is correct then the output will be true else false.


class Solution {
  public:
    vector<int> topoSort(int n, vector<vector<int>>& edg) {
        vector<int>ans;
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(int i = 0; i < edg.size(); i++){
           adj[edg[i][0]].push_back(edg[i][1]);
        }
        for(int i = 0; i < n; i++){
            for(auto it:adj[i]){
                degree[it]++;
            } 
        }
        queue<int>q;
        for(int i = 0 ; i< n; i++){
            if(degree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                degree[it]--;
                if(degree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};
