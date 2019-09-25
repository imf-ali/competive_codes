#include<bits/stdc++.h>
using namespace std;


struct node{
  int value;
  struct node *left,*right;
};

struct node* create(struct node *root,int data)
{
  
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->value=data;
  temp->left=NULL;
  temp->right=NULL;

    root=temp;
  return root;
}

struct node* insert(struct node *root,int data,int p)
{
  if(root==NULL)
  {
    cout<<p<<"\n";
    root=create(root,data);
  }

  else if(root->value > data)
    root->left=insert(root->left,data,2*p);

  else if(root->value < data)
    root->right=insert(root->right,data,2*p+1);

  return root;

}

struct node* delete1(struct node *root,int data,int p)
{
  


}

int main()
{

  int n;
  cin>>n;
  struct node *root=NULL;
  while(n--)
  {
    char q;
    int x;
    cin>>q>>x;
    if(q=='i')
    {
      //cout<<"i m here 1 with "<<x<<"\n";
      int k=1;
      root=insert(root,x,k);
    }
    if(q=='d')
    {
      int k=1;
      root=delete1(root,x,k);
    }
  }

  
  return 0;
}