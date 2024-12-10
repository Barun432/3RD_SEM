26. Write a C program to implement Binary Search.//
#include<stdio.h>
 int binarysearch(int arr[], int n, int target){
     int start =0;
     int end =n-1;
      int mid= (start+end)/2;
       while( start<=end){
        if(arr[mid]==target){
            return mid; // if found then return 
       }
        else if (target>arr[mid]){
            start=mid+1;
        }
        else if (target<arr[mid]){
            end=mid-1;
        }
        mid=(start+end)/2;
 }
 return -1;
 }
  int main(){
     int n=7;
      int arr[10]={10,20,30,40,50,60,70};
       int target;
    //    printf(" Enter the array element");
    //    for(int i=0;i<n;i++){
    //      scanf("%d",arr[i]);
          printf(" Enter the target value:");
           scanf("%d",&target);
          int ansid=binarysearch(arr,n,target);
           
           if(ansid==-1){
             printf("not found");
           }
           else{
             printf("target found");
           }
       }
  