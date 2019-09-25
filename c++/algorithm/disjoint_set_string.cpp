#include<bits/stdc++.h>
using namespace std;

map <string,string> visit;
map <string,int> val;

string root(string a)
{
    while(visit[a]!=a)
    {
      visit[a]=visit[visit[a]];

      a=visit[a];
    }

    return a;
}


int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;

    visit.clear();
    val.clear();
    
    while(n--)
    {
      string a,b;
      cin>>a>>b;

      if(!val[a])
      {
        val[a]=1;
        visit[a]=a;
      }

      if(!val[b])
      {
        val[b]=1;
        visit[b]=b;
      }

      string ra=root(a);
      string rb=root(b);

      if(ra!=rb)
      {
        visit[ra]=rb;
        val[rb]+=val[ra];
      }
      cout<<val[rb]<<"\n";
    }
  }
  return 0;
}