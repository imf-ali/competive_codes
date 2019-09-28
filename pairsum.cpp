#include<bits/stdc++.h>
using namespace std;

void fastscan(long long int &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c=='-') 
    { 
        negative = true;  
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    if (negative) 
        number *= -1; 
} 
  

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long int n,Q;
        cin>>n>>Q;
        long long int b[n-1];
        for(int i=0;i<n-1;i++)
        {
            //fastscan(b[i]);
            cin>>b[i];
        }

        while(Q--){
            long int p,q;
            cin>>p>>q;
            if(abs(p-q)%2==0)
                cout<<"UNKNOWN"<<"\n";

            else{

                long long int sum=0;
                if(min(p,q)%2==0)
                {
                    for(int i=min(p,q);i<max(p,q);i++)
                        sum+=(pow(-1,i)*b[i-1]);
                }

                else{
                    for(int i=min(p,q);i<max(p,q);i++)
                        sum+=(pow(-1,i+1)*b[i-1]);
                }

                cout<<sum<<"\n";
            }
            

        }

    } 
    return 0; 
}