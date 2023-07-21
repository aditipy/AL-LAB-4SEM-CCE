// DFS, BFS, MOTHER VERTEX ,TRANSPOSE

// #include <iostream>
// #include <stack>
// #include <queue>
// using namespace std;
// void dfs(int a[100][100],int v,int s)
// {
//   stack<int> stck;
//   int vis[v+1],u;
//   for(int i=1;i<=v;i++)
//     vis[i]=0;
//   stck.push(s);
//   vis[s]=1;
//   while(!stck.empty())
//   {
//       u=stck.top();
//       stck.pop();
//       cout<<u<<" ";
//       for(int i=1;i<=v;i++)
//       {
//           if(a[u][i]==1 && vis[i]==0)
//           {
//               stck.push(i);
//               vis[i]=1;
//           }
//       }
//   }
// }
// void bfs(int a[100][100],int v,int s)
// {
//   queue<int> que;
//   int vis[v+1],u;
//   for(int i=1;i<=v;i++)
//     vis[i]=0;
//   que.push(s);
//   vis[s]=1;
//   while(!que.empty())
//   {
//       u=que.front();
//       que.pop();
//       cout<<u<<" ";
//       for(int i=1;i<=v;i++)
//       {
//           if(a[u][i]==1 && vis[i]==0)
//           {
//               que.push(i);
//               vis[i]=1;
//           }
//       }
//   }
// }
// void mother(int a[100][100],int v,int s)
// {
//   stack<int> stck;
//   int vis[v+1],u,i;
//   for(int i=1;i<=v;i++)
//     vis[i]=0;
//   stck.push(s);
//   vis[s]=1;
//   while(!stck.empty())
//   {
//       u=stck.top();
//       stck.pop();
//       for(i=1;i<=v;i++)
//       {
//           if(a[u][i]==1 && vis[i]==0)
//           {
//               stck.push(i);
//               vis[i]=1;
//           }
//       }
//   }
//   for(i=1;i<=v;i++)
//   {
//       if(vis[i]==0)
//         return;
//   }
//   cout<<s<<" ";
// }
// void transpose(int a[100][100],int v,int s)
// {
//     int t[100][100];
//     for(int i=1;i<=v;i++)
//     {
//         for(int j=1;j<=v;j++)
//         {
//             t[i][j]=a[j][i];
//         }
//     }
//     bfs(t,v,s);
// }
// int main()
// {
//     int a[100][100],v,e,i,j,p,q,s;
//     cout<<"Enter Number of vertices:";
//     cin>>v;
//     cout<<"Enter number of edges:";
//     cin>>e;
//     for(i=1;i<=v;i++)
//     {
//         for(j=1;j<=v;j++)
//         {
//             a[i][j]=0;
//         }
//     }
//     for(i=1;i<=e;i++)
//     {
//         cout<<"Enter source of edge:";
//         cin>>p;
//         cout<<"Enter destination of edge:";
//         cin>>q;
//         a[p][q]=1;
//     }
//     cout<<"Enter source:";
//     cin>>s;
//     cout<<"DFS:";
//     dfs(a,v,s);
//     cout<<endl;
//     cout<<"BFS:";
//     bfs(a,v,s);
//     cout<<endl;
//     cout<<"Mother vertices are:";
//     for(i=1;i<=v;i++)
//     mother(a,v,i);
//     cout<<endl;
//     cout<<"BFS traversal of transpose of graph:";
//     transpose(a,v,s);

// }

// PATH
// #include <iostream>
// #include<stack>
// using namespace std;
// bool dfs(int a[100][100], int v, int s, int d)
// {
//     stack<int> stck;
//     int vis[v + 1], u;
//     for (int i = 1; i <= v; i++)
//         vis[i] = 0;
//     stck.push(s);
//     vis[s] = 1;
//     while (!stck.empty())
//     {
//         u = stck.top();
//         stck.pop();
//         cout << u << " ";
//         for (int i = 1; i <= v; i++)
//         {
//             if (a[u][i] == 1 && vis[i] == 0)
//             {
//                 stck.push(i);
//                 vis[i] = 1;
//             }
//         }
//     }
//     if(vis[d]==1)
//         return true;
//     else
//         return false;
// }

// int main()
// {
//     int a[100][100],v,e,i,j,p,q,s,d;
//     cout<<"Enter Number of vertices:";
//     cin>>v;
//     cout<<"Enter number of edges:";
//     cin>>e;
//     for(i=1;i<=v;i++)
//     {
//         for(j=1;j<=v;j++)
//         {
//             a[i][j]=0;
//         }
//     }
//     for(i=1;i<=e;i++)
//     {
//         cout<<"Enter source of edge:";
//         cin>>p;
//         cout<<"Enter destination of edge:";
//         cin>>q;
//         a[p][q]=1;
//     }
//     cout<<"Enter source:";
//     cin>>s;
//     cout<<"Enter detination:";
//     cin>>d;
//     if(dfs(a,v,s,d))
//         cout<<"Path exists";
//     else
//         cout<<"Path doesn't exists";
//     return 0;
// }

// CYCLIC
// #include <iostream>
// #include <stack>
// using namespace std;

// bool cyclic(int a[100][100], int v, int s)
// {
//     int count = 0;
//     stack<int> stk;
//     int vis[v + 1], u;
//     for (int i = 1; i <= v; i++)
//     {
//         vis[i] = 0;
//     }
//     stk.push(s);
//     vis[s] = 1;
//     count++;
//     while (!stk.empty())
//     {
//         u = stk.top();
//         stk.pop();
//         // cout<<u<<" ";
//         for (int i = 1; i <= v; i++)
//         {
//             if (a[u][i] == 1 && vis[i] == 0)
//             {
//                 stk.push(i);
//                 vis[i] = 1;
//                 count++;
//             }
//         }
//     }
//     if (count == v)
//         return true;
//     else
//         return false;
// }

// bool mother(int a[100][100], int v, int s)
// {
//     stack<int> stk;
//     int vis[v + 1], u, i;
//     for (int i = 1; i <= v; i++)
//         vis[i] = 0;
//     stk.push(s);
//     vis[s] = 1;
//     while (!stk.empty())
//     {
//         u = stk.top();
//         stk.pop();
//         for (i = 1; i <= v; i++)
//         {
//             if (a[u][i] == 1 && vis[i] == 0)
//             {
//                 stk.push(i);
//                 vis[i] = 1;
//             }
//         }
//     }
//     for (i = 1; i <= v; i++)
//     {
//         if (vis[i] == 1)
//         {
//             continue;
//         }
//         else if (vis[i] == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int a[100][100], v, e, i, j, p, q, s;
//     cout << "Enter Number of vertices:";
//     cin >> v;
//     cout << "Enter number of edges:";
//     cin >> e;
//     for (i = 1; i <= v; i++)
//     {
//         for (j = 1; j <= v; j++)
//         {
//             a[i][j] = 0;
//         }
//     }
//     for (i = 1; i <= e; i++)
//     {
//         cout << "Enter source of edge:";
//         cin >> p;
//         cout << "Enter destination of edge:";
//         cin >> q;
//         a[p][q] = 1;
//     }
//     for (int i = 1; i <= v; i++)
//     {
//         if (mother(a, v, i))
//         {
//             s = i;
//         }
//     }
//     if (cyclic(a, v, s))
//         cout << "Cyclic";
//     else
//         cout << "Not cyclic";
//     return 0;
// }

// CONNECTED
// #include <iostream>
// #include <stack>
// using namespace std;
// bool mother(int a[100][100], int v, int s)
// {
//     stack<int> stck;
//     int visited[v + 1], u, i;
//     for (int i = 1; i <= v; i++)
//         visited[i] = 0;
//     stck.push(s);
//     visited[s] = 1;
//     while (!stck.empty())
//     {
//         u = stck.top();
//         stck.pop();
//         for (i = 1; i <= v; i++)
//         {
//             if (a[u][i] == 1 && visited[i] == 0)
//             {
//                 stck.push(i);
//                 visited[i] = 1;
//             }
//         }
//     }
//     for (i = 1; i <= v; i++)
//     {
//         if (visited[i] == 1)
//         {
//             continue;
//         }
//         else if (visited[i] == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int a[100][100], v, e, i, j, p, q, m;
//     cout << "Enter Number of vertices:";
//     cin >> v;
//     cout << "Enter number of edges:";
//     cin >> e;
//     for (i = 1; i <= v; i++)
//     {
//         for (j = 1; j <= v; j++)
//         {
//             a[i][j] = 0;
//         }
//     }
//     for (i = 1; i <= e; i++)
//     {
//         cout << "Enter source of edge:";
//         cin >> p;
//         cout << "Enter destination of edge:";
//         cin >> q;
//         a[p][q] = 1;
//         a[q][p] = 1;
//     }
//     int count = 0;

//     for (int i = 1; i <= v; i++)
//     {
//         if (mother(a, v, i))
//         {
//             count++;
//         }
//     }
//     cout << count << endl;
//     if (count == v)
//         cout << "Connected graph";
//     else
//         cout << "Not connected";
// }

// KNAPSACK(GREEDY)
// #include<iostream>
// using namespace std;
// int knapsack(int w,int wt[],int val[],int n)
// {
//     if(n==0 || w==0)
//         return 0;
//     if(wt[n-1]>w)
//         return knapsack(w,wt,val,n-1);
//     else
//         return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1), knapsack(w,wt,val,n-1));
// }
// int main(){
//     int profit[100],weight[100],n,w;
//     cout<<"Enter no. of items:\n";
//     cin>>n;
//     cout<<"Enter profits:\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>profit[i];
//     }
//     cout<<"Enter weights:\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>weight[i];
//     }
//     cout<<"Enter target weight:\n";
//     cin>>w;
//     cout<<knapsack(w,weight,profit,n);

//     return 0;
// }

// CONTAINER LOADING(GREEDY)
// #include<iostream>
// using namespace std;
// void swap(int& xp, int& yp)
// {
//     int temp=xp;
//     xp=yp;
//     yp=temp;
// }

// void bubblesort(int arr[],int pos[],int n)
// {
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(arr[j]>arr[j+1])
//             {
//                 swap(arr[j],arr[j+1]);
//                 swap(pos[j],pos[j+1]);
//             }
//         }
//     }
// }
// int main(){
//     int n,c,i;
//     cout<<"enter no. of container:\n";
//     cin>>n;
//     cout<<"total capacity:\n";
//     cin>>c;
//     int W[n];
//     int X[n]={0};
//     int pos[n];

//     cout<<"Enter weights:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>W[i];
//         pos[i]=i;
//     }
//     bubblesort(W,pos,n);

//     for(i=0;i<n && W[i]<=c;i++)
//     {
//         X[pos[i]]=1;
//         c-=W[i];
//     }
//     cout<<"Selected items:\n";
//     for(i=0;i<n;i++)
//     {
//         cout<<X[i]<<" ";
//     }

//     return 0;
// }

// TOPOLOGICAL SORT
// #include <iostream>
// using namespace std;

// int main()
// {
//     int i,j,k,n,a[10][10] = {0},indeg[10]= {0},flag[10] = {0},count=0;
//     int m;

//     cout << "Enter the no of vertices:\n";
//     cin >> n;

//     cout << "Enter the no of edges:\n";
//     cin >> m;

//     int p,q;
//     cout<<"Enter Source and Desitnation vertices in the form  p q" << endl;
//     for(int i=0; i<m; i++)
//     {
//         cin>> p;
//         cin>> q;
//         a[p][q]=1;
//     }

//     for(i=1; i<=n; i++)
//         for(j=1; j<=n; j++){
//             indeg[i]=indeg[i]+a[j][i];
//         }

//     for(int i = 1; i <= n; i++){
//         cout << indeg[i] << " ";
//     }
//     cout << "\nThe topological order is:";

//     while(count<n)
//     {
//         for(k=1; k<=n; k++)
//         {
//             if((indeg[k]==0) && (flag[k]==0))
//             {
//                 cout << k << " ";
//                 flag [k]=1;
//             }

//             for(i=1; i<=n; i++)
//             {
//                 if(a[i][k]==1)
//                     indeg[k]--;
//             }
//         }
//         count++;
//     }
// return 0;
// }

// TRAVELLING SALESPERSON
#include<iostream>
using namespace std;
const int INF = 1e9;
int TSPbacktrack(int n,int graph[50][50],bool visited[],int curr_pos,int count,int cost,int& minCost)
{
    if(count==n && graph[curr_pos][0])
    {
        minCost=min(minCost,cost+graph[curr_pos][0]);
        return minCost;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && graph[curr_pos][i])
        {
            visited[i]=true;
            TSPbacktrack(n,graph,visited,i,count+1,cost+graph[curr_pos][i],minCost);
            visited[i]=false;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the no. of vertices"<<endl;
    cin>>n;
    int graph[50][50];
    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    bool visited[n];
    visited[0]=true;
    for(int i=1;i<n;i++)
    {
        visited[i]=false;
    }
    int minCost=INF;
    TSPbacktrack(n,graph,visited,0,1,0,minCost);
    cout<<"Minimum Cost:"<<minCost;

}




// DIJSKTRA'S
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define V 9

int minDist(int dist[], bool sptSet[])
{
    int min=INT32_MAX,min_index;
    for(int i=0;i<V;i++)
    {
        if(sptSet[i]==false && dist[i]<=min)
        {
            min=dist[i];
            min_index=i;

        }
    }
    return min_index;
}


void print(int dist[])
{
    cout<<"Vertex \t Distance from source\n";
    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t\t\t\t"<<dist[i]<<endl;
    }
}


void dijkstras(int graph[V][V],int src)
{
    int dist[V];
    bool sptSet[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT32_MAX;
        sptSet[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=minDist(sptSet,dist);
        sptSet[u]=true;
    }
    for(int i=0;i<V;i++)
    {
        if(!sptSet[v] && graph[u][v] && dist[u]!=INT32_MAX && dist[u]+graph[u][v]<dist[v])
        {
            dist[v]= dist[u]+graph[u][v];
        }
    }
    print(dist);
}


int main(){

    return 0;
}