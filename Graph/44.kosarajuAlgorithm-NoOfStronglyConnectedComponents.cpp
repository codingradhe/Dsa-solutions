
// 212. Kosaraju's algorithm
// You are given a directed graph with V vertices, numbered from 0 to V − 1,
//   and its adjacency list Adj, where Adj[i] contains all vertices j such that there is a
// directed edge from vertex i to vertex j.

// Your task is to find the number of strongly connected 
// components (SCCs) in the graph.



class Solution{
public:
    void newdfs(int node,vector<vector<int>> &newadj,vector<int>&vis,vector<int> &temp){
        vis[node] = 1;
        temp.push_back(node);
        for(auto it: newadj[node]){
            if(!vis[it]){
                newdfs(it,newadj,vis,temp);
            }
        }
        return ;
    }
    void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int>&st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj, vis,st);
            }
        }
        st.push(node);
    }
    int kosaraju(int V, vector<int> adj[]){
        stack<int>st;
        int n = V;
        vector<int>vis(n,0);
        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<vector<int>> newadj(n);
        for(int i = 0; i < n; i++){
            for(auto it: adj[i]){
                newadj[it].push_back(i);
            }
        }
        for(int i = 0; i < n; i++) vis[i] = 0;
        vector<vector<int>>result;
        int scc = 0;
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(!vis[it]){
                vector<int>temp;
                newdfs(it,newadj,vis,temp);
                scc++;
                result.push_back(temp);
            }
        }
        // return result if ask for return a 2d vector of strongly connected components
        return scc;
    }
};
