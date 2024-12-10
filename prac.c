#include<stdio.h>
 #include<stdlib.h>
struct node *create ( struct node *head);
 struct node *pop ( struct node *head);
  struct node *display (struct node *head);
  struct node {
     int data;
      struct node *next;  
  };
   int main(){
     struct node *head =NULL;
      int choice;
       do{
        printf("\t\n 1. create 2. delete 3. display\n");
         printf(" Enter the choice:\n");
          scanf("%d",&choice);
           switch(choice){
             case 1: head=create(head);
                         break;
              case 2 : head=pop(head);
                         break;
               case 3: display(head);
                         break;
           }
         }
          while(choice!=3);
          return 0;
   }
  
    struct node *create(struct node *head)
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
        if(head==NULL)
       {
           head=temp=newnode;
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
    return head;
}
    
     struct node *display(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
     struct node *pop( struct node *head){
           struct node *prev , *temp;
            temp=head;
             while(temp!=NULL){
                 prev=temp;
                 temp=temp->next;
                  
             }
           
                  printf("%d",prev->data);
                 temp=temp->next;
             return head;
                 
     }