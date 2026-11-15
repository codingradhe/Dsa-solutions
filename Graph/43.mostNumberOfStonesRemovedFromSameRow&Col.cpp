// 947. Most Stones Removed with Same Row or Column
// Solved
// Medium
// On a 2D plane, we place n stones at some integer coordinate points. 
//   Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or
// the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the
// location of the ith stone, return the largest possible number of stones that can be removed.

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool find(int u, int v) { return findUPar(u) == findUPar(v); }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    bool check(int row, int col, vector<vector<int>> &mat){
        int n = mat.size();
        for(int i = 0; i < n; i++){
            if(mat[i][col] == 1) return true;
        }
        for(int i = 0; i < n; i++){
            if(mat[row][i] == 1) return true;
        }
        return false;
    }
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        for(auto it: stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol , it[1]);
        }
        map<int,int> stonesnode;
        DisjointSet ds(maxrow + maxcol + 1);
        for(auto it :stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionBySize(noderow,nodecol);
            stonesnode[noderow] = 1;
            stonesnode[nodecol] = 1;
        }
        int ans = 0, cnt = 0;
        for(auto it : stonesnode){
            if(ds.findUPar(it.first) == it.first) cnt++;
        }
        int n = stones.size();
        return n - cnt ;
    }
};
