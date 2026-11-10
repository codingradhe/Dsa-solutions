// 1584. Min Cost to Connect All Points

// Medium
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance 
// between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there 
// is exactly one simple path between any two points.

 class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);

        dist[0] = 0;

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int mini = INT_MAX;
            int node = -1;
            // Find minimum distance unvisited node
            for(int j = 0; j < n; j++) {
                if(!vis[j] && dist[j] < mini) {
                    mini = dist[j];
                    node = j;
                }
            }

            vis[node] = true;
            ans += mini;

            // Update distances of remaining nodes
            for(int j = 0; j < n; j++) {
                if(!vis[j]) {
                    int d = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]);
                    dist[j] = min(dist[j], d);
                }
            }
        }

        return ans;
    }
};
