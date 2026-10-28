
// 969. Print Shortest Path
// Given a weighted undirected graph having n vertices numbered from 1 to n and m edges 
// describing there are edges, where edges[i]=[ai,bi,wi], representing an edge from vertex ai to bi with weight wi.

// Find the shortest path between the vertex 1 and the vertex n and if path does not exist 
// then return a list consisting of only -1.

// If there exists a path, then return a list whose first element is the weight of the path 
// and the remaining elements represent the shortest path from vertex 1 to vertex n.

// Note: On IDE only the total sum of weights will be shown as output. As there might
// be more than one path (The path will be validated through driver code and If wrong then output shown will be -2.).

        vector<vector<pair<int,int>>>adj(n + 1);
        for(auto it: edg){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>parent(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
        vector<int>dist(n + 1 ,1e9);
        dist[1] = 0;
        q.push({0,1});
        while(!q.empty()){
            auto p = q.top();
            int node = p.second;
            int d = p.first;
            q.pop();
            for(auto it:adj[node]){
                int adnode = it.first;
                int wt = it.second;
                if(wt + d < dist[adnode]){
                    dist[adnode] = wt + d;
                    q.push({dist[adnode],adnode});
                    parent[adnode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int>ans;
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        ans.insert(ans.begin(), dist[n]);
        return ans;
    }
};
