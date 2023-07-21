
#include <iostream>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;

bool isValidEdge(int u, int v, bool inMST[]) {
    return (inMST[u] ^ inMST[v]);
}

void primMST(int cost[][MAX_VERTICES], int V) { 
    bool inMST[MAX_VERTICES] = {false};
    inMST[0] = true;
    int edgeCount = 0, minCost = 0;

    while (edgeCount < V - 1) {
        int minEdge = INT_MAX, a = -1, b = -1;

        for (int i = 0; i < V; i++) {
            if (inMST[i]) {
                for (int j = 0; j < V; j++) {
                    if (!inMST[j] && cost[i][j] != 0 && cost[i][j] < minEdge) {
                        minEdge = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            cout << "Edge " << edgeCount++ << ": (" << a << ", " << b << ") cost: " << minEdge << endl;
            minCost += minEdge;
            inMST[b] = true;
        }
    }

    cout << "\nMinimum cost = " << minCost << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int cost[MAX_VERTICES][MAX_VERTICES] = {};

    cout << "Enter the edges in the format (u, v, cost):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cost[u - 1][v - 1] = c;
        cost[v - 1][u - 1] = c;
    }

    primMST(cost, V);

    return 0;
}
