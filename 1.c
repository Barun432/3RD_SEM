// #include<stdio.h>
// #include<string.h>
// int main(){
//     int n,i;
//     printf(" Enter the size \n ");
//     scanf("%d",&n);
//     int a[n];
//     printf(" Enter the Array Element\n");
//     scanf("%d",&a[i]);
// //     int result= are(a,n);
// //      printf("  second largest number :%d", result);
// // }
//     int max1=0;
//     for(i=0;i<n;i++){
//         if(a[i]>max1){
//             // max2=max1;
//             max1=a[i];
//         }
//         // else if( a[i]>max2&& a[i]<max1){
//         //     max2=a[i];   
//     }
//     printf(" %d",max1); 
//  }

 #include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to insert a node into the binary search tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal of the binary search tree
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search for a node in the binary search tree
struct node* search(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to delete a node from the binary search tree
struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left != NULL && root->right == NULL) {
            return root->left;
        } else if (root->left == NULL && root->right != NULL) {
            return root->right;
        }
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        free(temp);
        return root;
    } else {
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else {
            root->right = deleteNode(root->right, data);
        }
        return root;
    }
}

int main() {
    // Create the root node of the binary search tree
    struct node* root = NULL;

    // Insert nodes into the binary search tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // Print the inorder traversal of the binary search tree
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Search for a node in the binary search tree
    struct node* found = search(root, 5);
    if (found != NULL) {
        printf("Node %d found\n", found->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the binary search tree
    root = deleteNode(root, 7);

    // Print the inorder traversal of the updated binary search tree
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

 