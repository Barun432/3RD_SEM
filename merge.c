#include<stdio.h>
#include<stdlib.h>
void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int first [len1];
    int second [len2];

    //copy values
    int k= s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int j=0; j<len2; j++) {
        second[j] = arr[k];
        k++;
    }

    //merge 2 sorted arrays     
    int i = 0;
    int j = 0;
    k = s;

    while(i < len1 && j< len2) {
        if(first[i] < second[j]) {
            arr[k] = first[i];
            k++;
            i++;
        }
        else{
            arr[k] = second[j];
            k++;
            j++;
        }
    }   

    while(i < len1) {
        arr[k] = first[i];
        k++;
        i++;
    }

    while(j < len2 ) {
        arr[k] = second[j];
        k++;
        j++;
    }


}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

   int n;
  printf("Enter the array element  size:");
  scanf("%d",&n);
  int arr[n];
   printf("enter the array element ");
   for(int i=0;i<n;i++){
   scanf("%d",&arr[i]);
   }
    
 mergeSort(arr, 0, n-1);

      printf(" sorted array: \n");
     for(int i=0;i<n;i++){
    printf("%d", arr[i]);
}
}