#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // cout<<tst<<"\n";
        int n,m;
        cin>>n>>m;
        int j=0;
        int z=1;
        int x;
        bool tick[n];

        int k=m/n;
        int l=m%n;
        //cout<<l<<" ";

        if(k>0)
        {
            for(int i=0;i<k;i++)
            {
                for(int o=0;o<n;o++)
                  tick[o]=false;
                for(int w=0;w<n;w++)
                {
                  cin>>x;
                  if(tick[x-1]==true)
                  {
                    z=0;
                    //cout<<"i m here ";
                    j=1;
                  }

                 // cout<<x<<" ";
                  tick[x-1]=true;

                }
                
            }

        }

        for(int o=0;o<n;o++)
              tick[o]=false;
        if(l>0 && j==0)
        {
            for(int i=0;i<l;i++)
            {
                cin>>x;
                if(tick[x-1]==true)
                {
                    z=0;
                    //cout<<"i m here ";

                }
               // cout<<x<<" ";
                
                tick[x-1]=true;
            }
        }

        if(z==0)
            cout<<"NO"<<"\n";
        else
            cout<<"YES"<<"\n";

        //tst++;
    }
    return 0;
}