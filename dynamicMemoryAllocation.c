#include<stdio.h>
#include<stdlib.h>

int main() {
    //user input
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    //dynamic memory allocation
    int*arr = (int*)malloc(n*sizeof(int));
    if(arr==NULL) {
        printf("memory allocation failed !");
        return -1;
    }
    //populating the array
    for(int i=0;i<n;i++) {
        arr[i] = i*2;
    }
    //printing the array elements
    for(int i=0;i<n;i++) {
        printf("%d",arr[i]);
    }
    //freeing the allocated memory
    free(arr);
return 0;
}