#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, vector<bool> &done, int src)
{
    done[src]= true;
    cout<<src+1<<" ";
    for(int i=0;i<g[src].size();i++)
    {
        if(!done[g[src][i]])
        {
            dfs(g,done,g[src][i]);
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
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> done(n,false);
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            dfs(g,done,i);
            cout<<endl;
        }
    }
    
}
