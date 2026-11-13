// Count Islands After Every Operation
// Solved
// Given a grid of n rows and m columns. Initially, all cells of the grid contain 0, where 0 represents water.

// You are also given a 2D array operators[][], where each operator contains two 
// integers representing the row and column of a cell.
// Each operation converts the specified water cell into land by changing its value from 0 to 1.
// Return an array containing the number of islands after each operation.

// An island is a group of one or more land cells (or 1s) with the following properties,

// 1s are connected through their top, bottom, left, or right sides.
// Diagonally connected are not considered part of the same island.

class DisjointSet{
public:
    vector<int> parent , size;
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
        size.resize(n + 1, 0);
        for(int i = 0; i <= n; i++){
            size[i] = 1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
    bool isvalid(int row , int col , int n, int m){
        if(row >= 0&& row < n&& col >= 0 && col < m) return true;
        return false;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        DisjointSet ds(m*n);
        vector<int>vis(m*n ,0);
        vector<vector<int>> mat(n , vector<int>(m,0));
        vector<int>delrow =  {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        vector<int>ans;
        int cnt = 0;
        for(auto it : op){
            int row = it[0];
            int col = it[1];
            int node1 = row * m + col;
            if(vis[node1]){
                ans.push_back(cnt);
                continue;
            }
            vis[row * m + col] = 1;
            cnt++;
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                int node2 = nrow * m + ncol;
                if(isvalid(nrow,ncol,n,m) && vis[nrow * m + ncol]){
                    if(ds.findUPar(node1) != ds.findUPar(node2)) {
                        cnt--;
                        ds.unionBySize(node1,node2);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
