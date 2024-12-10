#include<stdio.h>
#include<stdlib.h>
 struct node *queue(struct node *head);
 struct node *dequeue(struct node *head );
 struct node *display (struct node *head);
struct node{
    int data;
    struct node *next;
};
 int main(){
     struct node *head=NULL;
     int choice;
    do{
        printf("1.queue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("Enter the choice:\n");
        scanf("%d",&choice);
         switch(choice){
            case 1:
             head= queue(head);
             break;
             case 2:
             head= dequeue(head);
             break;
             case 3:
              display(head);
             break;
         }
    }while(choice<=3);
      return 0;
 }

  struct node *queue(struct node *head){
     int choice;
     struct node *newnode=NULL, *temp=NULL;
     while (choice){
    newnode= (struct node*) malloc ( sizeof (struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data); 
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
     printf("Enter the choice(0 & 1)\n");
     scanf("%d",&choice);
     }
     return head;
  }


   struct node *dequeue(struct node *head ){
    struct node*temp;
    temp=head;
    head=temp->next;
    
    free(temp);
    return head;
   }


   struct node *display (struct node *head){
    struct node*temp;
    if(head==0){
        printf("queue is empty\n ");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
            printf("\n");
        }
    }
   }
  