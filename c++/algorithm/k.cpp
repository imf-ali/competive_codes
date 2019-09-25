#include<bits/stdc++.h>

using namespace std;


void pr(vector <int> a)
{
    int i;
    for(i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}

void change(vector <int> a)
{
    int i;
    for(i=0;i<a.size();i++)
    {
        a[i]=2*a[i];
    }

}

int main()
{
    vector <int> a;
    int t,n;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>n;
        a.push_back(n);
    }

    pr(a);

    cout<<endl;

    change(a);
    pr(a);
    //qs(a,0,a.size());
}