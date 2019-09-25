#include<bits/stdc++.h>
using namespace std;

bool a[251][251];
bool d[251][251];

int x;

void working(int i,int j,int n,int m)
{
    d[i][j]=1;
    
    if(i>0 && a[i-1][j]==1 && d[i-1][j]==0)
    {
    	x++;
    	
        working(i-1,j,n,m);
    }

    if(i<n-1 && a[i+1][j]==1 && d[i+1][j]==0)
    {
    	x++;
    
        working(i+1,j,n,m);
    }

    if(j>0 && a[i][j-1]==1 && d[i][j-1]==0)
    {
    	x++;
    
      	working(i,j-1,n,m);
    }

    if(j<m-1 && a[i][j+1]==1 && d[i][j+1]==0)
    {
 		x++;
 		
        working(i,j+1,n,m);
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
    
    	int n,m;
        cin>>n>>m;

        if(n==0 && m==0)
            break;


       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                d[i][j]=0;
            }
        }


        map <int,int> mp;
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            	
                if(a[i][j]==1 && d[i][j]==0)
                {
                	x=1;
               
                    working(i,j,n,m);
                    count++;
               
                    mp[x]++;
                }
 
              
            }
        }

        cout<<count<<"\n";

        for(auto k:mp)
        {
        	cout<<k.first<<" "<<k.second<<"\n";
        }

    }

    return 0;

}