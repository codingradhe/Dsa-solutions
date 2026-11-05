// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Medium
// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] =
//   [fromi, toi, weighti] represents a bidirectional and weighted edge between cities
// fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable
// through some path and whose distance is at most distanceThreshold, If 
//   there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is
// equal to the sum of the edges' weights along that path.

 class Solution {
public:
    void floyedWarshallAlgo(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] != 1e4 && mat[k][j] != 1e4) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        return;
    }
    int findTheCity(int n, vector<vector<int>>& edg, int thD) {
        int size = edg.size();
        vector<vector<int>> mat(n, vector<int>(n, 1e4));
        for (auto it : edg) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for (int i = 0; i < n; i++)
            mat[i][i] = 0;
        int ans;
        floyedWarshallAlgo(mat);
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (mat[i][j] <= thD)
                    cnt++;
            }
            if (cnt <= mini) {
                ans = i;
                mini = cnt;
            }
        }
        return ans;
    }
};
