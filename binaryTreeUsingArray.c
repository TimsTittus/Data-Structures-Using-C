#include <stdio.h> 
 
int main(){ 
    int limit, i, pos; 
    printf("Enter the total number of nodes: "); 
    scanf("%d", &limit); 
    int A[limit];   
    printf("Enter the node data: "); 
    for (i = 0; i < limit; i++){ 
        scanf("%d", &A[i]); 
    } 
    printf("the formed array nodes\n"); 
    for (i = 0; i < limit; i++){ 
        printf("%d\t", A[i]); 
    } 
    printf("\nEnter the position you want to check: "); 
    scanf("%d", &pos); 
    printf("\nthe element at position %d is...%d\n",pos,A[pos]); 
    if (pos < 0 || pos >= limit){ 
        printf("Invalid position\n"); 
        return 1;   
    } 
    if (pos > 0){ 
        printf("Parent of %d is: %d\n", A[pos], A[(pos-1) / 2]); 
    }  
    else{ 
        printf("No parent\n"); 
    } 
 
    if ((2 * pos)+1 >= limit){ 
        printf("No left child\n"); 
    } 
    else{ 
        printf("Left child of %d is: %d\n", A[pos], A[(2 * pos)+1]); 
    } 
    if ((2 * pos )+ 2 >= limit){ 
        printf("No right child\n"); 
    }  
    else{ 
        printf("Right child of %d is: %d\n", A[pos], A[(2 * pos )+ 2]); 
    } 
    return 0;   
} 
