/**

Given an undirected graph with n-vertices, calculated the minimum distance from source to all other vertices of graph using Dijkstra's

*/
#include <bits/stdc++.h>
using namespace std;

void findShortDistance(vector<vector<pair<int,int>>> &g, vector<int> &distance, int src)
{
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
    pq.push(make_pair(0, src));
    distance[src] = 0;
    while(!pq.empty())
    {
        int pqtop = pq.top().second;
        pq.pop();
        
        for(auto vertex : g[pqtop])
        {
            int adj = vertex.first;
            int weight = vertex.second;
            
            if(distance[adj]>distance[pqtop]+weight)
            {
                distance[adj] = distance[pqtop]+weight;
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

/**
Input:
7
9
0 1 2
0 2 6
1 3 5
2 3 8
3 4 10
3 5 15
4 5 6
4 6 2
5 6 6

Output:

Shortest distances
vertex 0: distance from source is 0
vertex 1: distance from source is 2
vertex 2: distance from source is 6
vertex 3: distance from source is 7
vertex 4: distance from source is 17
vertex 5: distance from source is 22
vertex 6: distance from source is 19

*/
