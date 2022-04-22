//785. Is Graph Bipartite? https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                queue <int> q;
                color[i]=1;
                q.push(i);
                
                while(!q.empty())
                {
                    int current = q.front();
                    q.pop();
                    for(int k: graph[current])
                    {
                        if(color[k] == -1)
                        {
                            color[k] = 1-color[current];
                            q.push(k);
                        }
                        else if(color[k] == color[current])
                        {
                            return false;
                        }
                    }
                }
            }    
        }
        return true;
    }
};
