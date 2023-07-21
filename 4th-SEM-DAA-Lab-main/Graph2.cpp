// 2nd way to represent graph(undirected graph)(using lists)
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
vector<int> adj[n+1];
cin>>n>>m;

for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    // in case of undirected , use both
    // in case of directed, use only the upper one as the edge is u---> v and not v---->u
    adj[v].push_back(u);
}

return 0;
}