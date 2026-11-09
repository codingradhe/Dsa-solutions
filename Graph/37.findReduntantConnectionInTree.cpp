// 684. Redundant Connection
// Medium
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with 
//   one additional edge added. The added edge has two different vertices chosen from 1 to n, 
//   and was not an edge that already existed. The graph is represented as an array edges of 
// length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes.
//   If there are multiple answers, return the answer that occurs last in the input.

 class Solution {
public:
    vector<int> parent, size;

    int findUPar(int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for(auto &it : edges) {

            int u = it[0];
            int v = it[1];

            if(findUPar(u) == findUPar(v)) {
                return {u, v};
            }

            unionBySize(u, v);
        }

        return {};
    }
};
