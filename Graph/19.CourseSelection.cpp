// 207. Course Schedule
// Solved
// Medium
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
//   You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
// take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& mat) {
        int n = num;
        vector<vector<int>> adj(n);
        vector<int>degree(n,0);
        for(int i = 0; i < mat.size();i++ ){
            adj[mat[i][1]].push_back(mat[i][0]);
        }
        for(int i = 0; i < n;i++){
            for(auto it: adj[i]){
                degree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < n ; i++){
            if(degree[i] == 0) q.push(i);
        }
        int ans = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans++;
            for(auto it:adj[x]){
                degree[it]--;
                if(degree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans == num;
    }
};
