// Beadth First Search(level order traversal)
// Always use the concept of Visited Array
// Take queue as data structure (FIFO)
// ask the ques who are your neighbours? check them keep them inside a queue and mark it as visited
        //      1
        //     / \
        //    2   6
        //   / \ / \
        //  3  4 7  8
        //     \/
        //      5

// #include<iostream>
// #include<queue>
// using namespace std;

// void bfs(int adj[][20],int m, int n, int src)
// {
//     int vis[30],a,b,i;
//     for(int i=1;i<=n;i++)
//     {
//         vis[i]=0;
//     }
//     int q[50],f=-1,r=-1;
//     q[++r]=src;
//     while(f<r)
//     {
//         a=q[++f];
//         for(b=1;b<=n;b++)
//         {
//             if(adj[a][b]==1 && vis[b]==0)
//             {
//                 vis[b]=1;
//                 q[++r]=b;
//             }
//         }
//         cout<<a<<" ";

//     }
// }

// int main()
// {
//     int m,n,u,v,src;
//     cout<<"Enter the number of edges and vertices in graph";
//     cin>>m>>n;
//     int adj[20][20];
//     cout<<"Enter the data";
//     for(int i=0;i<n;i++)
//     {
//         cin>>u>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }
//     cout<<"Enter the source";
//     cin>>src;
//     cout<<"BFS is:";
//     bfs(adj,m,n,src);
//     return 0;
// }


// #include <iostream>
// using namespace std;

// void bfs(int a[][10], int n , int s){
//     int visited[n+1];
//     int stk[n], top=-1;
//     for(int i =1;i<=n;i++){
//         visited[i] = 0;
//     }
//     int q[n],f,r;
//     f = r = -1;
//     q[++r] = s;
//     visited[s] = 1;
//     while(f<r){
//         int u = q[++f];
//         for(int i =1;i<=n;i++){
//             if(a[u][i] == 1 && visited[i]!=1){
//                 q[++r] = i;
//                 visited[i] = 1;
//             }
//         }
//         cout<<u<<"  ";  
//     }
// }

// int main(){

//     int n,e;
//     cout<<"Enter the number of vertices in the graph"<<endl;
//     cin>>n;
//     cout<<"Enter the number of edges in the graph"<<endl;
//     cin>>e;

//     int a[10][10];

//     for (int i=1;i<=e;i++){
//         int p,q;
//         cout<<"Enter the edge"<<endl;
//         cin>>p>>q;
//         a[p][q] = 1;
//     }

//     int s;
//     cout<<"Enter the value of source"<<endl;
//     cin>>s;

//     bfs(a,n,s);

//     return 0;
// }


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+2;
bool vis[N];
vector<int> adj[N];
int main(){
    int n,m,src;

cout<<"Enter the number of nodes and edges: \n";
cin>>n>>m;
for(int i=0;i<=n;i++)
{
    vis[i]=false;
}
cout<<"Enter data:\n";

for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    // in case of undirected , use both
    // in case of directed, use only the upper one as the edge is u---> v and not v---->u
    adj[v].push_back(u);
}
cout<<"Enter source:\n";
cin>>src;
queue<int> q;
q.push(src);
vis[src]=true;
cout<<"BFS is:\n";
while(!q.empty())
{
    int node=q.front();
    q.pop();
    cout<<node<<endl;

    vector<int>::iterator it;
    for(it=adj[node].begin();it!= adj[node].end();it++)
    {
        if(!vis[*it])
        {
            vis[*it]=1;
            q.push(*it);
        }
    }

}

return 0;
}