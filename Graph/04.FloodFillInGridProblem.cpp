// 733. Flood Fill
// Easy
// You are given an image represented by an m x n grid of integers image,
// where image[i][j] represents the pixel value of the image. You are also
// given three integers sr, sc, and color. Your task is to perform a flood
// fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent
// (pixels that share a side with the original pixel, either horizontally
// or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the 
// updated pixels and modifying their color if it matches the original
// color of the starting pixel.
// The process stops when there are no more adjacent pixels of the 
// original color to update.
// Return the modified image after performing the flood fill.

// better solution 
class Solution {
private:
    void dfs(int row,int col,vector<int>&delrow,vector<int>&delcol,vector<vector<int>>&mat,int color){
        int n = mat.size(),m = mat[0].size();
        int move = mat[row][col];
        mat[row][col] = color;
        for(int i = 0;i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == move && mat[nrow][ncol] != color){
                dfs(nrow,ncol,delrow,delcol,mat,color);
            }
        }
        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>mat = image;
        int change = image[sr][sc];
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        dfs(sr,sc,delrow,delcol,mat,color);
        return mat;
    }
};
// very brute solution
class Solution {
private:
    void dfs(int row,int col,vector<int>&delrow,vector<int>&delcol,vector<vector<int>>&mat,int color){
        int n = mat.size(),m = mat[0].size();
        int move = mat[row][col];
        mat[row][col] = color;
        for(int i = 0;i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == move && mat[nrow][ncol] != color){
                dfs(nrow,ncol,delrow,delcol,mat,color);
            }
        }
        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>mat;
        int change = image[sr][sc];
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        dfs(sr,sc,delrow,delcol,mat,color);
        return mat;
    }
};
