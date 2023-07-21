// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int cnt=0;
//     vector<vector<int>>adj(n);
//     vector<int>indeg(n,0);
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         indeg[v]++;
//     }
//     queue<int> que;
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         if(indeg[i]==0)
//         {
//             que.push(i);
//         }
//     }
//     while(!que.empty())
//     {
//         cnt++;
//         int x=que.front();
//         que.pop();
//         cout<<x<<" ";
//         for(auto it: adj[x])
//         {
//             indeg[it]--;
//             if(indeg[it]==0)
//             {
//                 que.push(it);
//             }
//         }
//     }
    
//     return 0;
// }


// #include <iostream>
// #include <stack>
// using namespace std;

// bool dfs(int a[100][100],int v,int s,int d)
// {
//   stack<int> stck;
//   int visited[v+1],u;
//   for(int i=1;i<=v;i++)
//     visited[i]=0;
//   stck.push(s);
//   visited[s]=1;
//   while(!stck.empty())
//   {
//       u=stck.top();
//       stck.pop();
//       //cout<<u<<" ";
//       for(int i=1;i<=v;i++)
//       {
//           if(a[u][i]==1 && visited[i]==0)
//           {
//               stck.push(i);
//               visited[i]=1;
//           }
//       }
//   }
//   if(visited[d]==1)
//     return true;
//   else
//     return false;
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
//     cout<<"Enter source of path:";
//     cin>>s;
//     cout<<"Enter destination of path:";
//     cin>>d;
//     if(dfs(a,v,s,d))
//         cout<<"Path exists";
//     else
//         cout<<"Path doesn't exist";
// }

#include <iostream>
using namespace std;

int main()
{
    int i,j,k,n,a[10][10] = {0},indeg[10]= {0},flag[10] = {0},count=0;
    int m;

    cout << "Enter the no of vertices:\n";
    cin >> n;

    cout << "Enter the no of edges:\n";
    cin >> m;

    int p,q;
    cout<<"Enter Source and Desitnation vertices in the form  p q" << endl;
    for(int i=0; i<m; i++)
    {
        cin>> p;
        cin>> q;
        a[p][q]=1;
    }

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++){
            indeg[i]=indeg[i]+a[j][i];
        }

    for(int i = 1; i <= n; i++){
        cout << indeg[i] << " ";
    }
    cout << "\nThe topological order is:";

    while(count<n)
    {
        for(k=1; k<=n; k++)
        {
            if((indeg[k]==0) && (flag[k]==0))
            {
                cout << k << " ";
                flag [k]=1;
            }

            for(i=1; i<=n; i++)
            {
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
        count++;
    }
return 0;
}