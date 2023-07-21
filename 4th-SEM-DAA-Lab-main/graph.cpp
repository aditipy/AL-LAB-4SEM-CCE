//1st way to represent graph(undirected graph)(using matrix)
#include<iostream>
using namespace std;
int main(){
int m,n;

cin>>n>>m;
cout<<"Hello";
int adj[n+1][m+1];
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    // in case of undirected , use both
    // in case of directed, use only the upper one as the edge is u---> v and not v---->u   
    adj[v][u]=1;
}
return 0;
}