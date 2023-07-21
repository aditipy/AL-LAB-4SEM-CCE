#include<iostream>
using namespace std;

int DAC_maxmin(int a[], int i, int j,int max, int min)
{
    
    int mid;
    if(i==j)
        max=min=a[i];
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
            max=a[i];
            min=a[j];
        }
    }
    mid=(i+j)/2;
    
    DAC_maxmin(a,i,mid,max,min);
    DAC_maxmin(a,j,mid+1,max,min);
    
    
}

int main(){
    int i,j,n;
    int max,min;
    cout<<"Total elements:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    i=a[0];
    j=a[n-1];
    DAC_maxmin(a,i,j,max,min);
    return 0;
}