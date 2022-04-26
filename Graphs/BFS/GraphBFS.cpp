#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &g, vector<bool> &done,int src)
{
    queue <int> q;
    q.push(src);
    done[src]=true;
    cout<<src+1<<" ";
    while(!q.empty())
    {
        int fr = q.front();
        q.pop();
        
        for(int i=0;i<g[fr].size();i++)
        {
            if(!done[g[fr][i]])
           {
                q.push(g[fr][i]);
                done[g[fr][i]]=true;
                cout<<g[fr][i]+1<<" "; 
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
            bfs(g,done,i);
            cout<<endl;
        }
    }
    
}
