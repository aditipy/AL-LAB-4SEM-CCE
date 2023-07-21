#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void dfs(int a[100][100],int v,int s)
{
  stack<int> stck;
  int visited[v+1],u;
  for(int i=1;i<=v;i++)
    visited[i]=0;
  stck.push(s);
  visited[s]=1;
  while(!stck.empty())
  {
      u=stck.top();
      stck.pop();
      cout<<u<<" ";
      for(int i=1;i<=v;i++)
      {
          if(a[u][i]==1 && visited[i]==0)
          {
              stck.push(i);
              visited[i]=1;
          }
      }
  }
}
void bfs(int a[100][100],int v,int s)
{
  queue<int> que;
  int visited[v+1],u;
  for(int i=1;i<=v;i++)
    visited[i]=0;
  que.push(s);
  visited[s]=1;
  while(!que.empty())
  {
      u=que.front();
      que.pop();
      cout<<u<<" ";
      for(int i=1;i<=v;i++)
      {
          if(a[u][i]==1 && visited[i]==0)
          {
              que.push(i);
              visited[i]=1;
          }
      }
  }
}
void mother(int a[100][100],int v,int s)
{
  stack<int> stck;
  int visited[v+1],u,i;
  for(int i=1;i<=v;i++)
    visited[i]=0;
  stck.push(s);
  visited[s]=1;
  while(!stck.empty())
  {
      u=stck.top();
      stck.pop();
      for(i=1;i<=v;i++)
      {
          if(a[u][i]==1 && visited[i]==0)
          {
              stck.push(i);
              visited[i]=1;
          }
      }
  }
  for(i=1;i<=v;i++)
  {
      if(visited[i]==0)
        return;
  }
  cout<<s<<" ";
}
void transpose(int a[100][100],int v,int s)
{
    int t[100][100];
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            t[i][j]=a[j][i];
        }
    }
    bfs(t,v,s);
}
int main()
{
    int a[100][100],v,e,i,j,p,q,s;
    cout<<"Enter Number of vertices:";
    cin>>v;
    cout<<"Enter number of edges:";
    cin>>e;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=1;i<=e;i++)
    {
        cout<<"Enter source of edge:";
        cin>>p;
        cout<<"Enter destination of edge:";
        cin>>q;
        a[p][q]=1;
    }
    cout<<"Enter source:";
    cin>>s;
    cout<<"DFS:";
    dfs(a,v,s);
    cout<<endl;
    cout<<"BFS:";
    bfs(a,v,s);
    cout<<endl;
    cout<<"Mother vertices are:";
    for(i=1;i<=v;i++)
    mother(a,v,i);
    cout<<endl;
    cout<<"BFS traversal of transpose of graph:";
    transpose(a,v,s);


}