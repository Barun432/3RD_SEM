// Create implementation OF BST and  traversing using  NON-Recursion
#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *left ,*right;
};
struct node *root=NULL,*newnode;
void create (struct node *root , struct node *newnode);
 void inorder(struct node *root);


void main(){
    int choice;
    int n,a;
    do{
       
     printf("\n ------BINARY S.T-----");
     printf(" \n-----------1.Create -------");
       printf(" \n-----------2.Inorder-------");
        printf(" \n-----------3.Preorder-------");
         printf(" \n-----------4.postorder-------");
          printf(" \n-----------5.EXit-------");
           printf("\n__________________________________________");
           printf("\nEnter your choice: ");
           scanf("%d",&choice);
           switch(choice){
             
            case 1: {
                while(a){
            printf("\nEnter the Data");
            scanf("%d",&n);
            newnode=(struct node*)malloc(sizeof (struct node));
           
            newnode->left=newnode->right=NULL;
             newnode->data=n;
            if(root==NULL)
          root=newnode;
          else
          create(root,newnode);

          printf("Do you want to be continue(0/1):");
          scanf("%d",&a);
                }
            
            
             break;
            }
            case 2: inorder(root);
            break;
            
              
           }
           
        }while(choice!=5);
}
void create (struct node *root, struct node *newnode){
     if(newnode->data<root->data){
     if(root->left==NULL)
        root->left=newnode;
         else
     create(root->left,newnode);
     }

      if(newnode->data>root->data){
     if(root->right==NULL)
        root->right=newnode;
     else
     create(root->right,newnode);
      }

      
      if(newnode->data==root->data)
      printf("Duplicate element not allowed");
}
   void inorder(struct node *root){
      
  }


