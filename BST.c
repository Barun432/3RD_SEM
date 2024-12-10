// Create implementation OF BST and  traversing using Recursion
#include<stdio.h>
#include<stdlib.h>

 struct node {
     int data;
      struct node *left , *right;
 };
struct node *root=NULL,*newnode;
 struct node *create(struct node *r , struct node *newnode);
  struct node *inorder(struct node *root);
  struct node *preorder(struct node *root);
  struct node *postorder(struct node *root);
//  struct node *delete(struct node *root ,int value);
//  struct node *search(struct node *root , int value);
//   struct node *min(struct node *root);
//   struct node *delete(struct node *root , int value);

  void main(){
    int chice;
    int choice,n;
     do{
     printf(" \n-----------TREE -------");
      printf(" \n-----------1.Create -------");
       printf(" \n-----------2.Inorder-------");
        printf(" \n-----------3.Preorder-------");
         printf(" \n-----------4.postorder-------");
          printf(" \n-----------5.search-------");
          printf(" \n-----------6.Minimum Node-------");
           printf(" \n-----------7. delete node -------");

           printf("\nEnter the choice:");
            scanf("%d",&choice);
             switch(choice){
                 case 1: {
                
                    while (chice){
                 printf("\n Enter the data:"); // For first node Create.
                 scanf("%d",&n);
                  newnode=(struct node*)(malloc(sizeof(struct node)));
                  newnode->left=newnode->right=NULL;
                  newnode->data=n;
                  if(root==NULL)
                     root=newnode;
                  
                  else
                    create(root,newnode); // for next node to Call the func. pass the root and newnode which created;

                printf("\nEnter your choice (0 or 1):"); //want to create  one more node.
                scanf("%d",&chice);
                 }
                 break;
                  
                 }
                 case 2: inorder(root);
                 break;

                  case 3: preorder(root);
                  break;

                  case 4: postorder(root);
                  break;

                //   case 5: root =search(root,8);
                //   if( root==NULL){
                //  printf("they not exist");
                //   }
                //   else{
                //   printf("they exist");
                //   }
                //   break;
                //   case 6: root= min(root);
                 
                //   break;
                //   case 7: delete(root,6);
                //   break;
             }
                 
     
  }while(choice!=8);

  }
   struct node *create(struct node *r , struct node *newnode){
          if(newnode->data<r->data){
             if(r->left==NULL)
                 r->left=newnode;
          else
            create(r->left,newnode);
   }
    if (newnode->data>r->data)
    {
        if(r->right==NULL)
            r->right=newnode;  
            else
        create(r->right,newnode);  
    }
    if(newnode->data==r->data)
    printf("\n Duplicate Element not allowed");
    
   }

   //FOR PRINTING THE TREE DATA 
   //  MANY FORM TRAVERSAL PRINTED
   struct node * inorder(struct node *root){
    if(root!=NULL) {
   inorder(root->left);
   printf("%d \t",root->data);
   inorder(root->right);
    }
   }


    struct node *preorder(struct node *root){
    if(root!=NULL){
        printf("\t%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
   }


    struct node *postorder(struct node *root){
    
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
    
        printf("\t %d", root->data);
    }
   }
// BST search tree
// struct node *min(struct node *root){
//   if(root=NULL){
//   return root;}
//   else if(root->left==NULL){
//      printf("%d",root->data);
//   return  root;
//   }
//   else{
//   return min(root->left);
//   }
// }

// searching of node present or node.
//  struct node *search(struct node *root , int value){
//    if(root==NULL)
//    return NULL;
//    else if (root->data==value)
//   return root;
//   else if(value<root->data)
//   search (root->left,value);
//   else if(value>root->data)
//   search(root->right,value);

//  }
   // we find the smallest number
//  struct node *inordersucc(struct node *root){
//   struct node*curr=root;
//   while(curr->left!=NULL){
//   curr=curr->left;
//   }
//   return curr;
//  }
//    //FOR DELETION CODE
//   struct node *delete (struct node *root , int value){
//     struct node *temp;
//         if(root==NULL)
//         return root;
//         else if (value<root->data)
//         root->left=delete(root->left,value);

//         else if (value>root->data)
//         root->right=delete(root->right,value);
//          else{
//           //case 1:// zerro child
//           if(root->left==NULL&&root->right==NULL){
//             root=NULL;
//             free(root);
//           }
//          //case 2:// one child
//           else if(root->left=NULL){
//           temp=root;
//           root=root->right;
//           free(temp);
//           return root;
//          }
//           else if(root->right=NULL){
//           temp=root;
//           root=root->left;
//           free(temp);
//           return root;
//           }
//           //case 3: // two child
//           else {
//              temp=inordersucc(root->right);
//              root->data=temp->data;
//              root->right=delete(root->right,temp->data);
//           }
//           }
//           return root;
          
// }