// //program to reverse a string using stack
#include<stdio.h>
#include<string.h>
int top=-1;
stack[100];
 void push( char s){
    if( top==s-1){
        printf("stack is overflow");
    }
     else{
        top++;
        stack[top]=s;

     }
 }
  char pop (){
 if(top==-1){
    printf("stack is underflow");

 }
 else{
     return stack[top--];
 }
  return -1;
  }
   int main(){
     char str[50];
      printf("Enter the string\n");
       scanf("%s",str);
        int len= strlen(str);
        // for passing the string through push func.
        for(int i=0;i<len;i++){
            push(str[i]);
        }
        // for print func.
        printf(" Reverse order: \n");
        for(int i=0;i<len;i++){
           str[i]= pop();
            printf("%c",str[i]);
        }
        return 0;
   }
