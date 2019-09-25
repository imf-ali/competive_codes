#include<bits/stdc++.h>
using namespace std;

int arr[1000000];

void initialize(int arr[],int v)
{
    for(int i=1;i<=v;i++)
        arr[i]=i;
}


int root(int i)
{
    while(arr[i]!=i)
        arr[i]=arr[arr[i]];
        i=arr[i];
    }

    return i;
}

void union1(int a,int b)
{
    int root_a=root(a);
    int root_b=root(b);

    arr[root_a]=arr[root_b];
}

int kruskal(pair <int,pair<int,int>> p[],int e,int v,int cost)
{
    cost=0;
    initialize(arr,v);
    for(int i=0;i<e;i++)
    {
        int m=p[i].second.first;
        int n=p[i].second.second;
        int weight=p[i].first;

        if(root(m)!=root(n))
        {
            cost+=weight;
            union1(m,n);
        }
    }

    return cost;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin>>v>>e;

    pair <int,pair<int,int>> p[e];
    for(int i=0;i<e;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        p[i]=make_pair(weight,make_pair(a,b));
    }

    sort(p,p+e);

    int cost=kruskal(p,e,v,cost);

    cout<<cost<<"\n";

    return 0;
}