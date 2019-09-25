#include<stdio.h>
#include<stdlib.h>

struct node{
	char vertex;
	int cost;
	struct node *next;
};


struct node* push(int a,char b,int price,struct node* head)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->vertex=b;
	temp->cost=price;
	temp->next=NULL;
	if(!head)
	{
		head=temp;
	}

	else
	{
		p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=temp;
	}

	return head;
}


int minDistance(int dis[],int state[],int V) 
{ 
   int min =1000000, min_index; 
   
    for (int v = 0; v < V; v++) 
    if (state[v] == 0 && dis[v] <= min) 
        min = dis[v], min_index = v; 
   
   return min_index; 
} 


void dijkstra(struct node *head[],int dis[],int state[],int v)
{
	dis[0]=0;
	for (int count = 0; count < v-1; count++) 
    { 
        
    	int u = minDistance(dis,state,v); 
   
    	state[u] = 1; 

		struct node *p=head[u];
    	while(p) 
		{
			char node=p->vertex;
			if (!state[(int)node-65] && dis[u] !=1000000 && dis[u]+p->cost < dis[(int)node-65]) 
            	dis[(int)node-65] = dis[u] + p->cost; 

			p=p->next;
		} 
    }

}

void printvals(int dis[],int v)
{
	for(int i=0;i<v;i++)
	{
		if(dis[i]==1000000)
		{
			int j=-1;
			printf("%d\n",j);
		}

		else
			printf("%d\n",dis[i]);
	}
}

int main()
{
	int t,v,e,price;
	char n1,n2;
	
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    
        int state[200]={0};
        int dis[200];
	    struct node *head[200]={'\0'};
		scanf("%d%d",&v,&e);
		
		for(int j=0;j<e;j++)
		{
			scanf("%c%c%d",&n1,&n2,&price);
			head[(int)n1-65]=push((int)n1-65,n2,price,head[(int)n1-65]);
		}
		
		for(int k=0;k<v;k++)
		{
		    dis[k]=1000000;
		}
		
		dijkstra(head,dis,state,v);
		
		printvals(dis,v);
		
	}

}
