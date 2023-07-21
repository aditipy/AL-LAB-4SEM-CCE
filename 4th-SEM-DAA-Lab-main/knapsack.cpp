#include<iostream>
using namespace std;

int knapsack(int w, int wt[], int val[], int n)
{
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]>w)
        return knapsack(w, wt, val, n-1);
    else
        return max(val[n-1] + knapsack(w-wt[n-1],wt,val,n-1), knapsack(w,wt, val, n-1));
}

int main(){
    int profit[100],weight[100],n,w;
    cout<<"Enter the no. of items: ";
    cin>>n;
    cout<<"Enter the profits: ";
    for(int i=0;i<n;i++)
    {
        cin>>profit[i];
    }
    cout<<"Enter the weights: ";
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    cout<<"Enter the target weight: ";
    cin>>w;
    cout<<knapsack(w, weight, profit, n)<<endl;
    return 0;
}