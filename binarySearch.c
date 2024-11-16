#include<stdio.h>
int main() {
    int arr[30],key,n,flag=0;
    printf("Enter the limit of array : ");
    scanf("%d",&n);
    printf("Enter the elements in the array : \n");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    
    printf("\nARRAY : ");
    for(int i=0;i<n;i++) {
        printf("%d",arr[i]);
    }
    
    printf("\nEnter the element to search : ");
    scanf("%d",&key);
    
    int mid,left=0,right=n-1;
    while(left<=right) {
        mid = (left+right)/2;
        
        if(arr[mid]==key) {
            printf("Element found at %d",mid+1);
            flag=1;
            break;
        }
        else if(arr[mid]<key) {
            left = mid+1;
        }
        else if(arr[mid]>key) {
            left = mid-1;
        }
    }
    if(flag==0) {
        printf("\nElement not found");
    }
    return 0;
}