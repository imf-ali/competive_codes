#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ipair;


int prim(vector <ipair> a[],int v,int source)
{
  vector <int> dis(v+1,INT_MAX);
  vector <bool> mst(v+1,false);
  int cost=0;

  priority_queue <ipair,vector<ipair>,greater<ipair>> pq;

  dis[source]=0;

  pq.push(make_pair(0,source));

  while(!pq.empty())
  {
    int x=pq.top().second;
    int y=pq.top().first; 
    pq.pop();

    if(mst[x]==true)
      continue;

    mst[x]=true;

    cost+=y;

    
    for(auto it: a[x])
    {
      if(mst[it.first]==false && it.second<dis[it.first])
      {

        dis[it.first]=it.second;
        pq.push(make_pair(dis[it.first],it.first));
        
      }
    }
  }

  return cost;
}


int main()
{
  int v,e;
  cin>>v>>e;

  vector <ipair> a[v+1];

  for(int i=1;i<=e;i++)
  {
    int x,y,weight;

    cin>>x>>y>>weight;

    a[x].push_back(make_pair(y,weight));
    a[y].push_back(make_pair(x,weight));
  }

  int source;
  cin>>source;

  int cost=prim(a,v,source);

  cout<<cost;

  return 0;
}