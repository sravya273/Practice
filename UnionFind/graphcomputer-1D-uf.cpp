/**
1319

https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
Any computer can reach any other computer directly or indirectly through the network.
You are given an initial computer network connections. 
You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int numConnections = connections.size();
        if(numConnections <n-1)
        return -1;

        UnionFind uf(n);
        for(int i=0;i<connections.size();i++)
        {
            uf.uni(connections[i][0],connections[i][1]);
        }
         
        int ans = 0;
        for(int i=0;i<n;i++) 
        {
            ans += uf.isGroupHead(i);
        }
        return ans-1;
    }
};
