/**
https://leetcode.com/problems/number-of-islands/
*/

class UnionFind {

    vector<int> p; //parent
    vector<int> r; //rank means max height in the tree

public:
    UnionFind(int size) {
        
        for(int i=0;i<size;i++) {
            p.push_back(i);
            r.push_back(0);
        }
    }
    
    int find(int x) {
        
        if(p[x] == x) {
            return x;
        }
        
        p[x] = find(p[x]); // compression
        return p[x];
    }
    
    void uni(int x, int y) {
        
        int px = find(x);
        int py = find(y);
        
        if(r[px] < r[py]) {
            p[px] = py;
        } else if(r[py] < r[px]) {
            p[py] = px;
        } else {
            p[py] = px;
            r[px]++;
        }
    }
    
    bool isGroupHead(int x) {
        return p[x]==x;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        UnionFind uf(n*m);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    if(i+1 < n && grid[i+1][j] == '1') {
                        uf.uni(m*i+j, m*(i+1)+j);
                    }  
                    if(j+1 < m && grid[i][j+1] == '1') {
                        uf.uni(m*i+j, m*i+j+1);
                    } 
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    ans += uf.isGroupHead(i*m+j);
                }
            }
        }
        return ans;
    }
};

