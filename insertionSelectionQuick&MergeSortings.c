#include <stdio.h> 
#include <stdlib.h> 
int arr[30]; 
void display(int n) { 
    for(int i=0;i<n;i++) { 
        printf("%d ",arr[i]); 
    } 
    printf("\n"); 
}

//SELECTION SORT
void SelectionSort(int n) { 
    for(int i=0;i<n-1;i++) { 
    int p=i; 
    for(int j=i+1;j<n;j++) { 
        if(arr[j]<arr[p]) { 
            p=j; 
        } 
    } 
    int temp=arr[p]; 
        arr[p]=arr[i]; 
        arr[i]=temp; 
    } 
    printf("Selection sort\n"); 
    display(n); 
}

//INSERTION SORT
void InsertionSort(int n) { 
    for(int i=1;i<n;i++) { 
    int key=arr[i]; 
    int j=i-1; 
    while(j>=0 && arr[j]>key) { 
        arr[j+1]=arr[j]; 
        j=j-1; 
    } 
    arr[j+1]=key; 
    } 
    printf("Insertion sort\n"); 
    display(n); 
}

//QUICK SORT
int partition(int low,int high) {
int p=arr[high]; 
int i=low-1; 
    for(int j=low;j<=high;j++) {
        if(arr[j]<p) { 
        i++; 
    int temp=arr[i]; 
    arr[i]=arr[j]; 
    arr[j]=temp; 
        } 
    } 
    int temp=arr[i+1]; 
    arr[i+1]=arr[high]; 
    arr[high]=temp; 
    return i+1; 
} 
void quickSort(int low,int high) { 
if(low<high) { 
    int p=partition(low,high); 
        quickSort(low,p-1); 
        quickSort(p+1,high); 
    } 
}

//MERGE SORT
void merge(int l, int m,int r) { 
int i=0,j=0,k=l; 
int n1=m-l+1; 
int n2=r-m; 
int L[n1],R[n2]; 
    for(int i=0;i<n1;i++) { 
        L[i]=arr[i+l]; 
    } 
    for(int j=0;j<n2;j++) { 
        R[j]=arr[m+1+j]; 
    } 
    while(i<n1 && j<n2) { 
        if(L[i]<=R[j]) { 
            arr[k]=L[i]; 
            i++; 
        } 
        else { 
            arr[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
    while(i<n1) { 
        arr[k]=L[i]; 
        i++; 
        k++; 
    } 
    while(j<n2) { 
        arr[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int l,int r) { 
    if(l<r) { 
        int m=l+(r-l)/2; 
        mergeSort(l,m); 
        mergeSort(m+1,r); 
        merge(l,m,r); 
    } 
}

int main() {
int n,choice; 
char chr[1]; 
printf("\n\t1.Selection Sort\n\t2.Insertion Sort\n\t3.Quick Sort\n\t4.MergeSort\n\t5.Exit\n"); 
do{
    printf("\nEnter number of elements: "); 
    scanf("%d",&n); 
    printf("Enter elements: "); 
    for(int i=0;i<n;i++) { 
        scanf("%d",&arr[i]); 
    }
  
    printf("\nEnter choice: "); 
    scanf("%d",&choice); 
    switch(choice) { 
    case 1: 
        InsertionSort(n); 
        break; 
    case 2: 
        SelectionSort(n); 
        break; 
    case 3: 
        quickSort(0,n-1); 
        printf("Quick Sort\n"); 
        display(n); 
        break; 
    case 4: 
        mergeSort(0,n-1); 
        printf("Merge Sort\n"); 
        display(n); 
        break; 
    case 5: 
    default: 
        printf("Exiting......\n"); 
        exit(0); 
        printf("Invalid Input"); 
        break; 
    }
    printf("Do you want to continue?(y/n) : "); 
    scanf("%s",chr); 
}while(chr[0]!='n'); 
} 