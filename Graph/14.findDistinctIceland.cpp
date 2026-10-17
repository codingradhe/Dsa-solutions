// Number of Distinct Islands
// Solved
// Given a grid grid[][] of size n × m, consisting of characters
// 'L' and 'W', where 'L' represents Land and 'W' represents Water
//   , find the number of distinct islands in the grid. 
// An island is a group of one or more land cells connected
// horizontally or vertically.

// Two islands are considered distinct if their shapes are
// different.
// Two islands have the same shape if one can be translated to
// match the other exactly. Rotation and reflection are not 
// allowed.
class Solution {
  public:
    bool isvalid(int row,int col,vector<vector<char>>&mat){
        int n = mat.size(), m = mat[0].size();
        if(row >=0&&row<n&& col >= 0&& col < m) return true;
        return false;
    }
    void count(int r,int c,vector<int>&vis,vector<pair<int,int>>&ans,vector<vector<char>>& mat){
        int n = mat.size(),m = mat[0].size();
        queue<int>q;
        ans.push_back({0,0});
        vis[r*m+c] = 1;
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        int bx = r,by = c;
        q.push(r*m+c);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                int node = q.front();
                q.pop();
                int row = node/m,col = node%m;
                for(int i = 0;i < 4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(isvalid(nrow,ncol,mat)&&!vis[nrow*m+ncol]&&mat[nrow][ncol] == 'L'){
                        q.push(nrow*m+ncol);
                        ans.push_back({(nrow-bx),(ncol-by)});
                        vis[nrow*m+ncol]= 1;
                    }
                }
            }
        }
        return ;
    }
    int countDistinctIslands(vector<vector<char>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        set<vector<pair<int,int>>>st;
        vector<int>vis(n*m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'L'&&!vis[i*m+j]){
                    vector<pair<int,int>>ans;
                    count(i,j,vis,ans,mat);
                    st.insert(ans);
                }
                
            }
        }
        return st.size();
    }
};
