#include <stdio.h>
 #include <stdlib.h>
 int main(){
 int top=-1;
 int n,opt;
 printf("Enter array limit ");
 scanf("%d",&n);
 int stack[n];
 do{
 printf("\n\n");
 printf("1. Push\n2. Pop\n3. Display\n4. Stop\n\n");
 printf("Enter an option ");
 scanf("%d",&opt);
 printf("\n");
 switch(opt){
 case 1: if (top==n){
 printf("Overflow");
 }
 else{
 for (int i=0;i<n;i++){
 printf("Enter elements (%d)",i+1);
 scanf("%d",&stack[i]);
 top++;
 }
 }
 break;
 case 2: if (top==-1)
 printf("Underflow\n");
 else{
 int a=stack[top];
 printf("The Popped element is %d",a);
 top--;
 }
 break;
 case 3: printf("THe elements are :\n");
 for (int i=0;i<=top;i++){
 printf("%d ",stack[i]);
 }
 printf("\n");
 break;
 case 4:
 printf("EXITING......\n");
 exit(0);
 default:
 printf("Invalid Option");
 break;
 }
 }while(opt!=4);
 }
