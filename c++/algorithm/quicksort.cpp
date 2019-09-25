#include<bits/stdc++.h>

using namespace std;


void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;

    return;
}


int partition(int a[],int low,int high)
{
    int pivot=a[high];

    int i=(low-1);

    for(int j=low;j<high-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }

    swap(&a[i+1],&a[high]);

    return (i+1);
}

void qs(int a[],int low,int high)
{
    int pi;
    if(low<high)
    {
        pi=partition(a,low,high);
    }

    qs(a,low,pi-1);
    qs(a,pi+1,high);
}


int main()
{
    int a[100];
    int t,n;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>n;
        a[k]=n;
    }

    // for(int i=0;i<a.size();i++)
    // {
    //     cout<<a[i]<<endl;
    // }


    qs(a,0,(t-1));
    for(int k=0;k<t;k++)
    {
        cout<<a[k]<<endl;
    }
}