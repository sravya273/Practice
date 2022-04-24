//1514. Path with Maximum Probability

// https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<vector<pair<int,double>>> g(n);
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            g[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));

        }
        vector<double>ans(n,0.0);
        ans[start]=1.0;
        
        findProb(ans,start,g);    
        return ans[end];
    }
    void findProb(vector<double> &ans, int start,vector<vector<pair<int,double>>> &g)
    {      
        priority_queue< pair<double, int>> pq;
        pq.push(make_pair(1.0,start));
        
        while(!pq.empty())
        {
            int vertex = pq.top().second;
            pq.pop();
        
            for(int i=0;i<g[vertex].size();i++)
            {
                int adj = g[vertex][i].first;
                double weight = g[vertex][i].second;
            
                if(ans[adj]<ans[vertex]*weight)
                {
                    ans[adj]=ans[vertex]*weight;
                    pq.push(make_pair(ans[adj],adj));
                }
            }
        }
    }
};
