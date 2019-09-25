#include<bits/stdc++.h>
using namespace std;


void initialize(int n)
{
  for(int i=0;i<n;i++)
  {
    arr[i]=i;
    size[i]=1;
  }
}

int root(int i)
{
   while(arr[i]!=i)
   {
     arr[i]=arr[arr[i]];

     i=arr[i];
   }
  return i;
}

bool find(int a,int b)
{
  if(root(a)==root(b))
    return true;

  else
    return false;
}

void union(int a,int b)
{
  int root_a=root(a);
  int root_b=root(b);

  if(size[root_a]<size[root_b])
  {
    arr[root_a]=arr[root_b];
    size[root_b]+=size[root_a];
  }

  else
  {
    arr[root_b]=arr[root_a];
    size[root_a]+=size[root_b];
  }
  
}


int main()
{
  int n;

  int *arr= new int[n];
  int *size=new size[n];

  



  return 0;
}