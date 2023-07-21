// #include <iostream>
// #include <algorithm>

// using namespace std;

// // Returns the maximum weight that can be loaded in the given container
// int containerLoading(int containerCapacity, int weights[], int weightsSize)
// {
//     // Create a 2D array to store the maximum weight that can be loaded for each item and remaining capacity
//     int dp[weightsSize + 1][containerCapacity + 1] = {0};

//     // Fill the array by solving subproblems in a bottom-up manner
//     for (int i = 1; i <= weightsSize; i++)
//     {
//         for (int j = 1; j <= containerCapacity; j++)
//         {
//             // If the current item fits in the remaining capacity, we can either take it or not
//             if (weights[i - 1] <= j)
//             {
//                 dp[i][j] = max(dp[i - 1][j - weights[i - 1]] + weights[i - 1], dp[i - 1][j]);
//             }
//             // Otherwise, we cannot take it
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     // Return the maximum weight that can be loaded in the container
//     return dp[weightsSize][containerCapacity];
// }

// int main()
// {
//     // Example usage;
//     int weights[] = {3, 4, 5, 9, 21};
//     int containerCapacity = 20;
//     int weightsSize = sizeof(weights) / sizeof(weights[0]);
//     int maxWeight = containerLoading(containerCapacity, weights, weightsSize);

//     cout<< maxWeight << endl;
//     return 0;
// }

// #include <iostream>
// #include <algorithm>

// using namespace std;

// // Returns the maximum weight that can be loaded in the given container
// int containerLoading(int containerCapacity, int weights[], int weightsSize)
// {
//     // Create a 2D array to store the maximum weight that can be loaded for each item and remaining capacity
//     int dp[weightsSize + 1][containerCapacity + 1] = {0};

//     // Fill the array by solving subproblems in a bottom-up manner
//     for (int i = 1; i <= weightsSize; i++)
//     {
//         for (int j = 1; j <= containerCapacity; j++)
//         {
//             // If the current item fits in the remaining capacity, we can either take it or not
//             if (weights[i - 1] <= j)
//             {
//                 dp[i][j] = max(dp[i - 1][j - weights[i - 1]] + weights[i - 1], dp[i - 1][j]);
//             }
//             // Otherwise, we cannot take it
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     // Return the maximum weight that can be loaded in the container
//     return dp[weightsSize][containerCapacity];
// }

// int main()
// {
//     // Example usage;
//     int weights[] = {3, 4, 5, 9, 21};
//     int containerCapacity = 20;
//     int maxWeight = containerLoading(containerCapacity, weights, 5);

//     cout<< maxWeight <<endl;
//     return 0;
// }




// #include<iostream>
// using namespace std;

// void swap(int *xp, int *yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }

// void bubbleSort(int arr[], int pos[], int n)
// {
//     int i, j;
//     for (i = 0; i < n-1; i++)
//         for (j = 0; j < n-i-1; j++)
//             if (arr[j] > arr[j+1]){
//                 swap(&arr[j], &arr[j+1]);
//                 swap(&pos[j], &pos[j+1]);
//             }
// }

// int main()
// {
//     int n, c;
//     cout << "Enter number of containers: " << endl;
//     cin >> n;
//     cout << "Enter total Capacity: " << endl;
//     cin >> c;

//     int W[n];
//     int X[n] = {0};
//     int pos[n];

//     cout << "Enter the weights:" << endl;
//     for(int i = 0; i < n; i++)
//     {
//         cin >> W[i];
//         pos[i] = i;
//     }

//     bubbleSort(W, pos, n);

//     for(int i = 0; i < n && W[i] <= c; i++){
//         X[pos[i]] = 1;
//         c -= W[i];
//     }

//     cout << "Selected Items: ";
//     for(int i = 0; i < n; i++){
//         cout << X[i] << " ";
//     }
// }


#include <iostream>
using namespace std;


void swap(int& xp, int& yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

void bubbleSort(int arr[], int pos[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap(pos[j], pos[j + 1]);
            }
        }
    }
}

int main()
{
    int n, c;
    cout << "Enter number of containers: " << endl;
    cin >> n;
    cout << "Enter total Capacity: " << endl;
    cin >> c;

    int W[n];
    int X[n] = { 0 };
    int pos[n];

    cout << "Enter the weights:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
        pos[i] = i;
    }

    bubbleSort(W, pos, n);

    for (int i = 0; i < n && W[i] <= c; i++)
    {
        X[pos[i]] = 1;
        c -= W[i];
    }

    cout << "Selected Items: ";
    for (int i = 0; i < n; i++)
    {
        cout << X[i] << " ";
    }

    return 0;
}
