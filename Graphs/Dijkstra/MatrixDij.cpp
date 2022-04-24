// https://leetcode.com/problems/path-with-minimum-effort/
// 1631. Path With Minimum Effort
struct node
{
    int x;
    int y;
    int weight;
};

struct CompareNode {
    bool operator()(node const& n1, node const& n2)
    {
        return n1.weight > n2.weight;
    }
};

class Solution {
public:
    int getWeight(vector<vector<int>> &matrix, int a, int b, int x, int y)
    {
        return abs(matrix[x][y] - matrix[a][b]);
    }
    
   void dijkstra(vector<vector<int>>& matrix,vector<vector<int>>& distance,int m, int n)
    {
        priority_queue< node, vector <node>, CompareNode> pq;
        pq.push({0,0,0});
        distance[0][0]=0;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty())
        {
            auto top = pq.top();
            int curx = top.x;
            int cury = top.y;
            int curw = top.weight;
            pq.pop();

            for(auto dir:dirs)
            {
                int adjx = curx+dir[0];
                int adjy = cury+dir[1];
                if(adjx>=0 && adjy>=0 && adjx<m && adjy<n)
                {   
                    int weight = getWeight(matrix,adjx,adjy,curx,cury);
                    int maxweight = max(curw,weight);
                    if(distance[adjx][adjy] >maxweight)
                    {
                        distance[adjx][adjy] =  maxweight;
                        pq.push({adjx,adjy, maxweight});
                    }
                }
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
        dijkstra(matrix,distance,m,n);
        return distance[m-1][n-1];
    }
};
