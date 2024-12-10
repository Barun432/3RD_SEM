#include<stdio.h>
void selection(int arr[],int n){
     for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        //swap(arr[i],arr[min])//
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        
     }
}
 int main(){
     int n=6;
      int arr[]={5,4,3,2,1 };
      selection(arr,n);
      printf(" sorted array: \n");
     for(int i=0;i<n;i++){
    printf("%d", arr[i]);
}      
 }