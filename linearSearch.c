#include <stdio.h>

int main() {
   int limit ,i,a[100];
   int flag=0;
   printf("enter the array limit : ");
   scanf("%d",&limit);
   
   printf("Enter the values : ");
   for(i=1;i<=limit;i++){
       scanf("%d",&a[i]);
   }
   
   int searchkey;
   printf("Ente the element to search : ");
   scanf("%d",&searchkey);
   
   for(i=1;i<=limit;i++){
       if(a[i]==searchkey){
           flag=1;
           break;
       }
   }
   if(flag==1){
       printf("Element is present ");
   }else {
       printf("element is not found");
   }
   
    return 0;
}