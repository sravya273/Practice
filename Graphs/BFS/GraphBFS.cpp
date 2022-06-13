/**
BFS traversal of an undirected graph with n-vertices and m-edges
*/

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &g, vector<bool> &done,int src)
{
    queue <int> q;
    q.push(src);
    done[src]=true;
    cout<<src<<" ";
    while(!q.empty())
    {
        int fr = q.front();
        q.pop();
        
        for(auto adj: g[fr])
        {
            if(!done[adj])
           {
                q.push(adj);
                done[adj]=true;
                cout<<adj<<" "; 
           }
        }
    }
    
}
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>> g(n);
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> done(n,false);
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            bfs(g,done,i);
            cout<<endl;
        }
    }
}

/**
Input: 

4
5
0 1
0 2
1 2
2 3
3 3

Output:
0 1 2 3 

*/
