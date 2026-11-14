// 827. Making A Large Island
// Solved
// Hard
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

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
    bool isvalid(int row, int col, int n) {
        if (row >= 0 && row < n && col >= 0 && col < n)
            return true;
        return false;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        vector<int> vis(n * n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];
                        if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                            ds.unionBySize(node, nrow * n + ncol);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];
                        if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                            st.insert(ds.findUPar(nrow * n + ncol));
                        }
                    }
                    int temp = 0;
                    for(auto it : st){
                        temp += ds.size[it];
                    }
                    temp++;
                    ans = max(ans , temp);
                }
            }
        }
        for(int i = 0; i < n * n; i++){
            ans = max(ans , ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};
