// 127. Floyd warshall algorithm
// Given a graph of V vertices numbered from 0 to V-1. Find the shortest distances between every 
// pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency
// matrix of size n x n. Matrix[i][j] denotes the weight of the edge from i to j. If matrix[i][j]=-1,
// it means there is no edge from i to j.


class Solution {
public:
	void shortestDistance(vector<vector<int>>&mat) {
        int n = mat.size();
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 1e9;
                }
                if(i == j) mat[i][j] = 0;
            }
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n ; i++){
                for(int j = 0; j < n ;j++){
                    if(mat[i][k] != 1e9 && mat[k][j] != 1e9){
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        // // negative cycle detection
        // for(int i = 0 ; i < n; i++){
        //     if(mat[i][i] < 0) cout<< "negative cycle is found"<<endl;
        // }

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1e9){
                    mat[i][j] = -1;
                }
            }
        }
        return;
	}
};
