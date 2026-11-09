// 810. Disjoint Set
// Design a disjoint set (also called union-find) data
// structure that supports the following operations:

// DisjointSet(int n) initializes the disjoint set with n elements.

// void unionByRank(int u, int v) merges the sets containing u and v using the rank heuristic.

// void unionBySize(int u, int v) merges the sets containing u and v using the size heuristic.

// bool find(int u, int v) checks if the elements u and v are in the same
// set and returns true if they are, otherwise false.

class DisjointSet {
public:
    vector<int>rank , parent , size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
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

    bool find(int u, int v) {
        return findUPar(u) == findUPar(v);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = parent[ulp_u];
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = parent[ulp_v];
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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

  
