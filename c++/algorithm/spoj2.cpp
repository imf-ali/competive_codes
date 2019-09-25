// #include <boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
// namespace mp = boost::multiprecision;
using namespace std;


bool check(string s)
{
  for(int i=0;i<s.length();i++)
  {
    if(s[i]==0)
      return false;
  }

  return true;


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
    string s;
    cin>>s;

    
    for(int i=0;i< s.length();i++)
    {
      
      for(int j=0;j<s.length();j++)
      {
        if(s[j]=='1')
        {
          s[j]='-1';
          if(j+1<s.length())
          {
            if(s[j+1]=='1')
              s[j+1]='0';
            else if(s[j+1]=='0')
              s[j+1]='1';
          }
          if(j-1>=0)
          {
            if(s[j-1]=='1')
              s[j-1]='0';
            else if(s[j-1]=='0')
              s[j-1]='1';
          }
        }

      }
    }

    bool get=check(s);

    if(get)
      cout<<"WIN"<<"\n";
    
    else
      cout<<"LOSE"<<"\n";
  }
  
  return 0;
}