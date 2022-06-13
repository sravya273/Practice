/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Note: Use visited array, we cannot edit the given input
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //'1's (land) and '0's (water), return the number of islands.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    ans++;
                    dfs(grid,i,j,m,n,visited);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int i,int j,int m,int n, vector<vector<bool>> &visited)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0'|| visited[i][j])
        {
            return;
        }  
        visited[i][j]=true;
        dfs(grid,i-1,j,m,n,visited);
        dfs(grid,i+1,j,m,n,visited);
        dfs(grid,i,j-1,m,n,visited);
        dfs(grid,i,j+1,m,n,visited);
    }
};
