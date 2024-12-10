#include<stdio.h>
#include<stdlib.h>
struct node *create( struct node *head);
struct node *delete_beign(struct node *head);
struct node *display(struct node *head);
struct node *delete_End(struct node *head);
struct node *delete_pos(struct node *head);

struct node{
    int data;
    struct node *next;
};
int main(){
    struct  node *head=NULL;
    int choice;
    
    do{
     printf("\n1.Create\n");
     printf("2.delete beign\n");
     printf("3.delete End\n");
     printf("4.delete pos:\n");
     printf("5.display\n");
    printf("Enter the choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
      
        case 1:
            head= create(head);
             break;
        case 2: 
            head=delete_beign(head);
                 break;
        case 3:
             head=delete_End(head);
                break;
        case 4: 
            head=delete_pos(head);
            break;
        case 5: 
            display(head);
            break;
    } 
    }
    while (choice!=5);
    return 0;

}
    struct node *create( struct node *head){
        int choice;
        struct node  *newnode=NULL ,*temp=NULL;
        while(choice){
       newnode= (struct node*) malloc(sizeof(struct node));
       printf("Enter the data\n");
       scanf("%d",&newnode->data);
        newnode->next=NULL;
       if(head==NULL){
        head=newnode;
        temp=newnode;
       }
       else{
        temp->next=newnode;
        temp=newnode;
       }
       
       
     printf("Enter your choice (0 or 1)\n");
       scanf("%d",&choice);
          
        }
       
        return head;
    }


    struct node *delete_beign(struct node *head){
        struct node *temp=NULL;
        temp=head;
        head=temp->next;
        free(temp);
        return head;
    }


    struct node *delete_pos(struct node *head){
        struct node *temp=NULL , *nextnode=NULL;
        int pos,i=1;
        temp=head;
        printf("Enter the pos:\n");
        scanf("%d",&pos);
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
           return head;
    }


 struct node *delete_End(struct node *head){
    struct node *prev,*temp;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp; 
        temp=temp->next;   
    }
    prev->next=NULL;
    return head;
 }

 struct node *display(struct node *head){
    struct node *temp=NULL;
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
 }