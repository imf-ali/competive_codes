#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *pre,*link;
};

struct node* output(struct node* start,int n)
{
    for(int i=0;i<n;i++)
    {
        struct node* p=(struct node*)malloc(sizeof(struct node));
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        int a;
        scanf("%d ",&a);
        if(start==NULL)
        {

            p->data=a;
            p->link=NULL;
            start=p;
            p->pre=NULL;
        }
        else
        {
            p=start;
            while(p->link!=NULL)
            p=p->link;
            temp->data=a;
            p->link=temp;
            temp->pre=p;
            temp->link=NULL;
        }
    }
    return start;
}

void small(struct node* start)
{
    struct node* p=start;
    int low;
    while(p!=NULL)
    {
        if(p==start)
        {
            low=p->data;
            p=p->link;
        }
        else
        if(p->data<low)
        {
            low=p->data;
            p=p->link;
        }
    }
    printf("%d\n",low);
}

struct node *del(struct node *start)
{
    struct node *p=start;
    int greatr=-99999;
    while(p!=NULL)
    {
        if(p->data>greatr)
        greatr=p->data;
        p=p->link;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p==start)
        {
            if(p->data==greatr)
            {
                start=p->link;
                p->link->pre=start;
            }
        }
        
        if(p->link->data==greatr)
        {
            struct node *q=(struct node*)malloc(sizeof(struct node));
            q=p->link;
            p->link=q->link;
            q->link->pre=p;
            free(q);
        }
        p=p->link;
    }
    p=start;
    return p;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        struct node* start=NULL;
        int n;
        scanf("%d",&n);
        start=output(start,n);
        //small(start);
        struct node *newstart=NULL;
        newstart=del(start);
        while(newstart!=NULL)
        {
            printf("%d ", newstart->data);
            newstart=newstart->link;
        }
    }
    return 0;
}