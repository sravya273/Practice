#include <bits/stdc++.h>
using namespace std;

void findShortDistance(vector<vector<pair<int,int>>> &g, vector<int> &distance, int src)
{
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
    pq.push(make_pair(0, src));
    distance[src] = 0;
    
    while(!pq.empty())
    {
        int vertex = pq.top().second;
        pq.pop();
        
        for(int i=0;i<g[vertex].size();i++)
        {
            int adj = g[vertex][i].first;
            int weight = g[vertex][i].second;
            
            if(distance[adj]>distance[vertex]+weight)
            {
                distance[adj] = distance[vertex]+weight;
                pq.push(make_pair(distance[adj],adj));
            }
        }
    }
}

int main() {
	int n,m,u,v,weight;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    while(m--)
    {
        cin>>u>>v;
        cin>>weight;
        //Depends on input
        // u--;
        // v--;
        g[u].push_back(make_pair(v,weight));
        g[v].push_back(make_pair(u,weight));
    }
    cout<<"Graph Creation"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        cout<<i<<g[i][j].first<<g[i][j].second<<endl; 
    }
    vector<int> distance(n,INT_MAX);
    findShortDistance(g,distance,0);
    
    cout<<"Shortest distances"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"vertex "<<i<<": distance from source is "<<distance[i]<<endl; 
    }
	return 0;
}
