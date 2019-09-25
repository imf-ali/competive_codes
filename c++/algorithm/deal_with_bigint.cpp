#include <boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n,q;
  cin>>n>>q;
 
    mp::cpp_int a[n]; 
    mp::cpp_int b[n];

  for(int i=0;i<n;i++)
    cin>>a[i];

  for(int i=0;i<n;i++)
    cin>>b[i];

  while (q--)
  {
    mp::cpp_int val=0;
    int m,n;
    cin>>m>>n;
    for(int j=m-1;j<=n-1;j++)
      val+=(a[j]*b[j]);

    cout<<val<<"\n";
  }
  
  




  return 0;
}