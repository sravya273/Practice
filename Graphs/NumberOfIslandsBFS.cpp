/**
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        queue <pair<int,int>> q;
        q.push(make_pair(i,j));
        grid[i][j] = '0';
        
        while(!q.empty())
        {
            pair<int,int> top = q.front();
            int topx = top.first;
            int topy = top.second;
            q.pop();
            if(topx+1<m && grid[topx+1][topy]=='1')
            {
                grid[topx+1][topy]='0';
                q.push(make_pair(topx+1,topy));
            }
            if(topx-1>=0 && grid[topx-1][topy]=='1')
            {
                grid[topx-1][topy]='0';
                q.push(make_pair(topx-1,topy));
            }
            if(topy+1<n && grid[topx][topy+1]=='1')
            {
                grid[topx][topy+1]='0';
                q.push(make_pair(topx,topy+1));
            }
            if(topy-1>=0 && grid[topx][topy-1]=='1')
            {
                grid[topx][topy-1]='0';
                q.push(make_pair(topx,topy-1));
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    bfs(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
};
