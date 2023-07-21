#include <iostream>
using namespace std;
int partition(int a[], int low, int high)
{
    int i, j, pivot, temp;
    i=low+1;
    j=high;
    pivot=a[low];
    while(1)
    {
        while(a[i]<pivot && i<high)
            i++;
        while(pivot<a[j])
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[j];
            a[j]=a[low];
            a[low]=temp;
            return j;
        }
    }
}
void quicksort(int a[], int low, int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main() 
{
    int n, i;
    cout<<"enter no. of elements and array\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cout<<"enter element\n";
        cin>>a[i];
    }
    quicksort(a,0,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}