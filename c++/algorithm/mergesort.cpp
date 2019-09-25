#include<bits/stdc++.h>

using namespace std;

void merge(int a[],int left,int right)
{
    int mid=(left+right)/2;

    int pos=left;

    int lsize=mid-left+1,rsize=right-mid;
    int larr[lsize],rarr[rsize];

    for(int i=0;i<lsize;i++)
    {
        larr[i]=a[left+i];
    }
    for(int i=0;i<rsize;i++)
    {
        rarr[i]=a[mid+1+i];
    }
    int i=0,j=0;
    while(i<lsize && j<rsize)
    {
        if(larr[i]<=rarr[i])
            a[pos++]=larr[i++];
        
        else
            a[pos++]=rarr[j++];
    }

    while(i<lsize)
    {
        a[pos++]=larr[i++];
    }

    while(j<rsize)
    {
        a[pos++]=rarr[j++];
    }

}

void mergesort(int a[],int left,int right)
{
    int mid=(left+right)/2;

    if(left==right)
        return;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);

    merge(a,left,right);

}

int main()
{
    int a[100];
    int t,n;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>t;
        a[k]=t;
    }

    // for(int i=0;i<a.size();i++)
    // {
    //     cout<<a[i]<<endl;
    // }


    mergesort(a,0,n-1);


    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<endl;
    }
}