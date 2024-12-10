#include<stdio.h>
#include<stdlib.h>
// Q is denoted HEAD.

struct node *create(struct node *Q);
struct node *insertatlast(struct node *Q);
struct node *display(struct node *Q);
struct node *insertatbeign(struct node *Q);
struct node *insertatposition(struct node *Q);
struct node *length(struct node *Q);
struct node {
    int data;
    struct node * next;
    // struct node * pre;
};

int main()
{
    int choice;
    struct node *Q=NULL;
    do
    {
        printf("\n1.Create\n");
        printf("2.InsertatLast\n");
        printf("3.Insertatbeign\n");
        printf("4.insertatposition\n");
        printf("5.Display\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            Q=create(Q);
            break;
        case 2:
           Q=insertatlast(Q);   
           break;
        case 3:
           Q=insertatbeign(Q);
           break;
        case 4: 
          Q=insertatposition(Q);
            break;
        case 5:
          Q=length(Q);
           break;  
        case 6:
            display(Q);
            break;
    
        }
    } while(choice<=6);
    return 0;    
}
struct node *create(struct node *Q)
{
    int choice;
    struct node *newnode=NULL, *temp=NULL;
    while (choice)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        // newnode->pre=NULL;
        if(Q==NULL)
       {
           Q=temp=newnode;
       }
       else
       {
           temp->next=newnode;
        //    newnode->pre=temp;
           temp=newnode;
       }
       printf("Enter your choice (0 or 1)\n");
       scanf("%d",&choice);
    }
    return Q;
}


struct node *display(struct node *Q)
{
    struct node *temp=NULL;
    temp=Q;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}


struct node *insertatlast(struct node *Q)
{
    struct node *newnode=NULL, *temp=NULL;
    int count;
    temp=Q;
    while (temp->next != NULL)
    {
        temp=temp->next;
        count++;
    }
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp->next=newnode;
    // newnode->pre=newnode;

    return Q;
}

    struct node *insertatbeign(struct node *Q){
        struct node *newnode=NULL;
        newnode=(struct node*) malloc(sizeof(struct node));
        printf("Enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next=Q;
        Q=newnode;

        return Q;
        
    }
    struct node *insertatposition(struct node *Q){
        int pos,i=1,count;
        struct node *temp, *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode->data);
        printf("Enter the position\n");
        scanf("%d",&pos);
        
        if(pos>count){
            printf("full L.L");
        }
        else{
            temp=Q;
        while (i<pos){
            temp=temp->next;
            i++;
        }   
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return Q;
        
    }
    struct node *length(struct node *Q){
        int count=0;
        struct node *temp=NULL;
        while(temp!=0){
            count++;
            temp=temp->next;
        }
        printf("Length is: %d",count);
        return Q;
    }
