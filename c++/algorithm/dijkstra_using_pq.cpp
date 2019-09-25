#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ipair;

void dijkstra(vector <ipair> a[],int s,int v)
{
  priority_queue<ipair,vector<ipair>,greater<ipair>> pq;

  vector <int> dis(v+1,INT_MAX);
  vector <bool> vis(v+1,false);

  dis[s]=0;
  pq.push(make_pair(0,s));
  while(!pq.empty())
  {
    int x=pq.top().second;
    pq.pop();
    if(vis[x]!=0)
     continue;

    vis[x]=true;
    

    for(auto it: a[x])
    {
      if(dis[x]+(it).second<dis[(it).first] && vis[it.first]==0)
      {
        dis[(it).first]=dis[x]+(it).second;
        //cout<<"distance of "<<it.first<<" is "<<dis[(it).first]<<"\n";
        pq.push(make_pair(dis[(it).first],(it).first));

      }
    }

  }


  for(int i=1;i<=v;i++)
  {
  	if(i==s)
  		continue;
  	else if(!vis[i])
  		cout<<"-1 ";
  	else
  		cout<<dis[i]<<" ";
  }

  cout<<"\n";
  return ;
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--)
  {
    int v,e,source;
    cin>>v>>e;

    vector <ipair> edges[v+1];

    while(e--)
    {
      int a,b,cost;
      cin>>a>>b>>cost;
      edges[a].push_back(make_pair(b,cost));
      edges[b].push_back(make_pair(a,cost));
    }

    cin>>source;
    dijkstra(edges,source,v);

    // if(k==INT_MAX)
    // {
    //   cout<<"NONE"<<"\n";
    // }

    // else
    //   cout<<k<<"\n";

  }

  return 0;
}

