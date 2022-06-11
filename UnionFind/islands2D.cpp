/**
https://leetcode.com/problems/number-of-islands/
*/


class UnionFind {
    vector<vector<pair<int,int>>> parent; // parent(i,j) -> x,y
    vector<vector<int>> rank; // (i,j)-> rank is r

    public:
    
    UnionFind(int m, int n) 
    {
        parent.resize(m,vector<pair<int,int>>(n));
        rank.resize(m,vector<int>(n));
        
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++)
            {
                parent[i][j] = {i,j};
                rank[i][j] = 0;
            }
        }
    }

    void setParent(pair<int,int> p1,pair<int,int> p2)
    {
        parent[p1.first][p1.second] = p2;
    }

    int getRank(pair<int,int> p)
    {
        return rank[p.first][p.second];
    }

    pair<int,int> doFind(pair<int,int> p)
    {
        if(parent[p.first][p.second] == p)
        {
            return p;
        }
        parent[p.first][p.second] = doFind(parent[p.first][p.second]);
        return parent[p.first][p.second];
    }

    void doUnion(pair<int,int> pair1, pair<int,int> pair2)
    {
        pair<int,int> parent1 = doFind(pair1);
        pair<int,int> parent2 = doFind(pair2);

        int parent1Rank = getRank(parent1);
        int parent2Rank = getRank(parent2);
        
        if(parent1Rank > parent2Rank)
        {
            setParent(parent2,parent1);
        }
        else if(parent1Rank < parent2Rank)
        {
            setParent(parent1,parent2);
        }
        else
        {
            setParent(parent1,parent2);
            rank[parent2.first][parent2.second]++;
        }
    }
    bool isGroupHead(int i, int j)
    {
        return (parent[i][j] == make_pair(i,j));
    }
};    

class Solution 
{
public:
    bool isValid(int i, int j, int m, int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m,n);
        
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(grid[i][j] == '1') 
                {
                    if(isValid(i+1,j,m,n) && grid[i+1][j] == '1') 
                    {
                        uf.doUnion({i,j},{i+1,j});
                    }  
                    if(isValid(i,j+1,m,n) && grid[i][j+1] == '1') 
                    {
                        uf.doUnion({i,j},{i,j+1});
                    } 
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(grid[i][j] == '1') 
                {
                    ans += uf.isGroupHead(i,j);
                }
            }
        }
        return ans;
    }
};
