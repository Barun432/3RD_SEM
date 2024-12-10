// //To convert the infix to postfix expression
// #include<stdio.h>
//  int top=-1;
//  char stack[100];
//   void push( char c){
//     if( top==c-1){
//         printf(" stack is full");
//     }
//     else{
//         top++;
//         stack[top]=c;
//     }
//   }
//   char pop(){
//     if(top==-1){
//         printf(" stack is empty");
//     }
//     else{
//         return stack[top--];
//     }
//   }
//    int pr( char x){
//     if(x=='(')
//     return 0;
//     if(x=='+'|| x=='-')
//     return 1;
//      if(x=='*'|| x=='/')
//      return 2;
//    }
//    int main(){
//     char exp[100];
//      char*e,x;
//     printf(" Enter the experssion\n");
//     scanf("%s",exp);
//     printf("\n");
//     e=exp;
//     while(*e!='\0'){
//         if(isalnum(*e))
//         printf("%c",*e);
//         else if(*e=='(')
//         push(*e);
//          else if(*e==')'){
//             while(x=pop()!='(')
//             printf("%c",x);
//          }
//          else{
//             while( pr(stack[top])>=pr(*e))
//             printf("%c",pop());
//             push(*e);
//          }
//          e++;
//     }
//     while(top!=-1){
//         printf("%c", pop());

//     }
//     return 0;
//    }
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node Node;

void create(Node** poly, int coef, int exp) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    
    if (*poly == NULL) {
        *poly = temp;
        return;
    }
    
    Node* current = *poly;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
        create(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            create(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            create(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        create(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        create(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    
    return result;
}

int main(void) {
    Node* poly1 = NULL,*poly2 = NULL;
    create(&poly1, 5, 4);
    create(&poly1, 3, 2);
    create(&poly1, -1, 1);

    create(&poly2, -4, 4);
    create(&poly2, 2, 2);
    create(&poly2, 1, 0);

    printf("First polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);

    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);
    return 0;
}

