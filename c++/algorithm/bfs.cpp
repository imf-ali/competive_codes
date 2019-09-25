#include<bits/stdc++.h>
using namespace std;

void bfs(int source,int state[],vector <int> a[],int dis[])
{
    queue <int> done;
    state[source]=1;
    done.push(source);

    while(!done.empty())
    {
        int k=done.front();
        done.pop();
        vector <int> ::iterator it;
        for(it=a[k].begin();it!=a[k].end();it++)
        {
            if(state[*it]!=1)
            {
                done.push(*it);
                state[*it]=1;
                dis[*it]=dis[k]+6;
            }
        }
    }

    return ;

}


int main()
{
    int q;
    
    cin>>q;
    while(q--)
    {
        int n,e;
        cin>>n>>e;
        int *state=new int[n+1]();
        vector <int> a[n+1];
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);

        }

        int source;
        cin>>source;

        int *dis=new int[n+1]();
        

        
        bfs(source,state,a,dis);
        
        for(int i=1;i<=n;i++)
        {
            if(state[i]!=1)
                cout<<"-1"<<" ";

            else if(i==source)
                continue;

            else
                cout<<dis[i]<<" ";    
        }

        cout<<endl;
    }



    return 0;
}
