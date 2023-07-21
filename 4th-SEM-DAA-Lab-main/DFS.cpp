// Depth First Search(pre order traversal)
// Always use the concept of Visited Array
// Take stack as data structure (LIFO)
// ask the ques who are your neighbours? check them keep them inside a stack and mark it as visited
        //      1
        //     / \
        //    2   6
        //   / \ / \
        //  3  4 7  8
        //     \/
        //      5

// #include<iostream>
// #include<stack>
// using namespace std;
// void dfs(int adj[][20],int n, int src)
// {
//     int vis[30],a,b,i;
//     for(int i=1;i<=n;i++)
//     {
//         vis[i]=0;
//     }
//     int s[50],top=-1;
//     s[++top]=src;
//     vis[src]=1;
//     while(top>=0)
//     {
//         a=s[top--];
//         for(b=1;b<=n;b++)
//         {
//             if(adj[a][b]==1 && vis[b]==0)
//             {
//                 vis[b]=1;
//                 s[++top]=b;
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
//     cout<<"DFS is:";
//     dfs(adj,n,src);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void dfs(int a[][10], int n, int e, int s){
//     int visited[n+1];
//     int stk[n], top=-1;
//     for(int i=1;i<=n;i++){   
//         visited[i] = 0;
//     }
//     visited[s] = 1;
//     stk[++top] = s;
//     cout<<"Dfs started"<<endl;
//     while (top>=0){
//         int u = stk[top--];
//         for(int i =1;i<=n;i++){
//             if(a[u][i] == 1 && visited[i]!=1){
//                 stk[++top] = i;
//                 visited[i] = 1;
//             }
//         }
//         cout<<u<<"  ";
//     }
//     cout<<endl;
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
//     cout<<"Enter the source"<<endl;
//     cin>>s;

//     dfs(a,n,e,s);

//     return 0;
// }

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int N=1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    //preorder
    vis[node]=1;
    cout<<node<<" ";
    // cout<<endl;

    //inorder
    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(vis[*it]);
        else
        {
            dfs(*it);
        }   
    }

    //if postorder
    // cout<<node<<" ";

}
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
cout<<endl;
dfs(src);
return 0;
}