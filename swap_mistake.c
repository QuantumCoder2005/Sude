//swap mistake
#include<stdio.h>


void main(){
    int arr[100];

    int size;

    printf("Enter size of array: ");
    scanf("%d",&size);

    for(int i=0;i<size;i++){
        printf("\nEnter %d element of array: ",i+1);
        scanf("%d",&arr[i]);
    }

    int lower, upper;

    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            upper = i;
            break;
        }
    }

    for(int i=size-1;i>0;i--){
        if(arr[i]<arr[i-1]){
            lower = i;
            break;
        }
    }
    printf("The swapped elements are (%d,%d) and their indexes are %d and %d respectfully",arr[lower],arr[upper],lower,upper);

}

