// #include <bits/stdc++.h>
// using namespace std;
  
// const int MAX = 100;
// int store[MAX], n;
// int graph[MAX][MAX];
// int d[MAX];

// bool is_clique(int b)
// {
//     for (int i = 1; i < b; i++)
//     {
//         for (int j = i + 1; j < b; j++)
//             if (graph[store[i]][store[j]] == 0)
//                 return false;
//     }
//     return true;
// }

// int maxCliques(int i, int l)
// {
//     int max_ = 0;
//     for (int j = i + 1; j <= n; j++) 
//     {
//         store[l] = j;
//         if (is_clique(l + 1)) 
//         {
//             max_ = max(max_, l);
//             max_ = max(max_, maxCliques(j, l + 1));
//         }
//     }
//     return max_;
// }
// int main()
// {
//     int edges[][2] = { { 1, 2 }, { 2, 3 }, { 3, 1 }, { 4, 2 } };
//     int size = 4;
//     n = 4;
//     for (int i = 0; i < size; i++) 
//     {
//         graph[edges[i][0]][edges[i][1]] = 1;
//         graph[edges[i][1]][edges[i][0]] = 1;
//         d[edges[i][0]]++;
//         d[edges[i][1]]++;
//     }
//     cout << maxCliques(0, 1);
//     return 0;
// }

// Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;
// // global variables
// // problem instance globals (note: I waste index 0 to match textbook )
// float w[] = {-1, 4, 7, 5, 3 }; // item weights - previously SORTED in ascending order of profit per weight
// float p[] = {-1, 40, 63, 25, 12 }; // item profits
// int n; // number of items
// float W = 10.0; // knapsack weight limit
// // best solution found (note: I waste index 0 to match textbook )
// float maxprofit = 0.0;
// bool bestset[] = {false, false, false, false, false };
// // global node state
// bool includes[] = {false, false, false, false, false };
// bool promising(int i, float weight, float profit)
// {
//     float totweight, boundOnProfit;
//     int k;
//     if (weight > W)
//         return false;
//     totweight = weight;
//     boundOnProfit = profit;
//     for (int j=i+1; j<=n; j++)
//     {
//         if (totweight + w[j] <= W)
//         {
//             totweight += w[j];
//             boundOnProfit += p[j];
//         }
//         else
//         {
//             k = j;
//             boundOnProfit += p[k] * (W - totweight) / w[k];
//             break;
//         } // end if
//     } // end for
//     return boundOnProfit > maxprofit;
// } // end promising
// void knapsack(int i, float weight, float profit)
// {
//     if (weight <= W && profit > maxprofit)
//     {
//         maxprofit = profit;
//         for (int index=1; index <= n; index++)
//         {
//             bestset[index] = includes[index];
//         } // end for
//     } // end if
//     if (promising(i, weight, profit))
//     {
//         includes[i+1] = true;
//         knapsack(i+1, weight + w[i+1], profit + p[i+1]);
//         includes[i+1] = false;
//         knapsack(i+1, weight, profit);
//     } // end if
// } // end knapsack
// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++){

//     }
//     knapsack(0, 0.0, 0.0); // inital call to kick off the backtracking
// // print results
//     cout << "Best profit: " << maxprofit << endl;
//     cout << "Items stolen should be:" << endl;
//     for (int index = 1; index <= n; index++)
//     {
//         if (bestset[index])
//         {
//             cout << "item " << index << endl;
//         } // end if
//     } // end for
// } // end main



// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int MAX_N = 20;
// int n, m;
// int w[MAX_N], b[MAX_N], x[MAX_N], best_x[MAX_N];
// int curr_w, curr_b, best_b;

// void branch_and_bound(int i) {
//     if (i > n) {
//         if (curr_b > best_b) {
//             best_b = curr_b;
//             for (int j = 1; j <= n; j++) {
//                 best_x[j] = x[j];
//             }
//         }
//         return;
//     }

//     if (curr_w + w[i] <= m) {
//         curr_w += w[i];
//         curr_b += b[i];
//         x[i] = 1;
//         branch_and_bound(i + 1);
//         curr_w -= w[i];
//         curr_b -= b[i];
//         x[i] = 0;
//     }

//     if (curr_b + (m - curr_w) * b[i + 1] > best_b) {
//         x[i] = 0;
//         branch_and_bound(i + 1);
//         x[i] = 1;
//     }
// }

// int main() {
//     cout << "Enter the number of items: ";
//     cin >> n;

//     cout << "Enter the capacity of the container: ";
//     cin >> m;

//     cout << "Enter the weight and benefit of each item:\n";
//     for (int i = 1; i <= n; i++) {
//         cin >> w[i] >> b[i];
//     }

//     sort(b + 1, b + n + 1, greater<int>());
//     curr_w = curr_b = best_b = 0;

//     branch_and_bound(1);

//     cout << "The maximum benefit is: " << best_b << endl;
//     cout << "The items in the container are:\n";
//     for (int i = 1; i <= n; i++) {
//         if (best_x[i] == 1) {
//             cout << "Item " << i << endl;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10;
const int INF = 1e9;

int n, cost[MAX_N][MAX_N], min_cost = INF;
int curr_cost, curr_path[MAX_N], best_path[MAX_N];
bool used[MAX_N];

int get_lower_bound(int node) {
    int lower_bound = 0;
    int min1 = INF, min2 = INF;

    for (int i = 0; i < n; i++) {
        if (i != node && !used[i]) {
            if (cost[node][i] < min1) {
                min2 = min1;
                min1 = cost[node][i];
            } else if (cost[node][i] < min2) {
                min2 = cost[node][i];
            }
        }
    }

    lower_bound += min1 + min2;
    for (int i = 0; i < n; i++) {
        if (i != node && !used[i]) {
            int min_edge = INF;
            for (int j = 0; j < n; j++) {
                if (j != node && i != j && !used[j]) {
                    min_edge = min(min_edge, cost[i][j]);
                }
            }
            lower_bound += min_edge;
        }
    }

    return (lower_bound + 1) / 2;
}

void tsp(int node, int depth) {
    if (depth == n) {
        curr_cost += cost[node][0];
        if (curr_cost < min_cost) {
            min_cost = curr_cost;
            for (int i = 0; i < n; i++) {
                best_path[i] = curr_path[i];
            }
        }
        curr_cost -= cost[node][0];
        return;
    }

    if (curr_cost + get_lower_bound(node) >= min_cost) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            curr_cost += cost[node][i];
            used[i] = true;
            curr_path[depth] = i;
            tsp(i, depth + 1);
            curr_cost -= cost[node][i];
            used[i] = false;
        }
    }
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    used[0] = true;
    curr_path[0] = 0;
    tsp(0, 1);

    cout << "Minimum cost: " << min_cost << endl;
    cout << "Path: ";
    for (int i = 0; i < n; i++) {
        cout << best_path[i] << " ";
    }
    cout << endl;

    return 0;
}
