
// #include <iostream>
// #include <limits.h>
// using namespace std;

// // Number of vertices in the graph
// #define V 6

// // A utility function to find the vertex with minimum
// // distance value, from the set of vertices not yet included
// // in shortest path tree
// int minDistance(int dist[], bool sptSet[])
// {
//     // Initialize min value
//     int min = INT_MAX, min_index;

//     for (int v = 0; v < V; v++)
//         if (sptSet[v] == false && dist[v] <= min)
//             min = dist[v], min_index = v;

//     return min_index;
// }

// // A utility function to print the constructed distance
// // array
// void printSolution(int dist[])
// {
//     cout << "Vertex \t Distance from Source" << endl;
//     for (int i = 0; i < V; i++)
//         cout << i << " \t\t\t\t" << dist[i] << endl;
// }

// // Function that implements Dijkstra's single source
// // shortest path algorithm for a graph represented using
// // adjacency matrix representation
// void dijkstra(int graph[V][V], int src)
// {
//     int dist[V]; // The output array.  dist[i] will hold the shortest
//                  // distance from src to i
//     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
//                     // path tree or shortest distance from src to i is finalized

//     // Initialize all distances as INFINITE and sptSet[] as false
//     for (int i = 0; i < V; i++)
//         dist[i] = INT_MAX, sptSet[i] = false;

//     // Distance of source vertex from itself is always 0
//     dist[src] = 0;

//     // Find shortest path for all vertices
//     for (int count = 0; count < V - 1; count++) {
//         // Pick the minimum distance vertex from the set of vertices not yet processed.
//         int u = minDistance(dist, sptSet);

//         // Mark the picked vertex as processed
//         sptSet[u] = true;

//         // Update dist value of the adjacent vertices of the picked vertex.
//         for (int v = 0; v < V; v++)
//             // Update dist[v] only if is not in sptSet, there is an edge from u to v, and
//             // total weight of path from src to v through u is smaller than current value of dist[v]
//             if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
//                 dist[v] = dist[u] + graph[u][v];
//     }

//     // print the constructed distance array
//     printSolution(dist);
// }

// // driver's code
// int main()
// {
//     int graph[V][V];
//     cout << "Enter the adjacency matrix representation of the graph:" << endl;
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             cin >> graph[i][j];
//         }
//     }

//     int src;
//     cout << "Enter the source vertex: ";
//     cin >> src;

//     // Function call
//     dijkstra(graph, src);

//     return 0;
// }

#include <iostream>
#include <climits>
using namespace std;
int findmin(int distance[100], bool visited[100], int v)
{
    int minvertex = -1;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && (minvertex == -1 || distance[i] < distance[minvertex]))
            minvertex = i;
    }
    return minvertex;
}
void dijkstra(int arr[100][100], int v)
{
    int distance[100];
    bool visited[100];
    for (int i = 0; i < v; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for (int i = 0; i < v; i++)
    {
        int minvertex = findmin(distance, visited, v);
        visited[minvertex] = true;
        for (int j = 0; j < v; j++)
        {
            if (arr[minvertex][j] != 0 && !visited[j])
            {
                int dist = distance[minvertex] + arr[minvertex][j];
                if (dist < distance[j])
                    distance[j] = dist;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << i << "->" << distance[i] << endl;
    }
}
int main()
{
    int v, e, i, j, p, q, r;
    cout << "Enter number of vertices and edges:";
    cin >> v >> e;
    int arr[100][100];
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            arr[i][j] = 0;
    }
    cout << "Enter edges and weight:";
    for (i = 0; i < e; i++)
    {
        cin >> p >> q >> r;
        arr[p][q] = r;
    }
    dijkstra(arr, v);
}