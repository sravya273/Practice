/**
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution {
public:
    void bfs(const vector<vector<char>>& grid, vector<vector<bool>>&visited, int i, int j, int m, int n)
    {
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        queue <pair<int,int>> q;
        q.push(make_pair(i,j));
        visited[i][j] = true;
        
        while(!q.empty())
        {
            pair<int,int> top = q.front();
            int topx = top.first;
            int topy = top.second;
            q.pop();
            for(int i=0;i<dirs.size();i++)
            {
                int r = topx+dirs[i][0];
                int c = topy+dirs[i][1];
                if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1' && visited[r][c]==false)
                {
                    visited[r][c] = true;
                    q.push(make_pair(r,c));
                }
            }
        }
        return;
    }
    int numIslands(const vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    count++;
                    bfs(grid,visited,i,j,m,n);
                }
            }
        }
        return count;
    }
};
