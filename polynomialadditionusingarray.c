#include<stdio.h>

struct poly{
    int coeff;
    int expo;
}p1[10],p2[10],p3[10];

int readPoly(struct poly p[10]){
    int t;
    printf("Enter the number of elements : ");
    scanf("%d",&t);
    printf("\n Enter the coeff & expo in descending order");
    for(int i=0;i<t;i++){
        printf("Enter coefficient (%d) : ",i+1);
        scanf("%d",&p[i].coeff);
        printf("Enter exponent (%d) : ",i+1);
        scanf("%d",&p[i].expo);
        printf("\n");
    }
    return t;
}

void display(struct poly p[10],int t) {
    for(int i=0;i<t-1;i++){
        printf("%d(x^%d) + ",p[i].coeff,p[i].expo);
    }
    printf("%d(x^%d)",p[t-1].coeff,p[t-1].expo);
}

int addPoly(struct poly p1[10],int t1,struct poly p2[10],int t2,struct poly p3[10]) {
    int i=0,j=0,k=0;
    while(i<t1 && j<t2) {
        if(p1[i].expo==p2[j].expo) {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
        else if(p1[i].expo>p2[j].expo) {
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
        else {
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j++;k++;
        }
    }
while(i<t1) {
    p3[k].coeff=p1[i].coeff;
    p3[k].expo=p1[i].coeff;
    i++;k++;
}
while(j<t2) {
    p3[k].coeff=p2[j].coeff;
    p3[k].expo=p2[j].expo;
    j++;k++;
}
return k;
}

int main() {
    int t1,t2,t3;
    printf("\n\nFirst Polynomial\n\n");
    t1=readPoly(p1);
    display(p1,t1);
    printf("\n\nSecond Polynomial\n\n");
    t2=readPoly(p2);
    display(p2,t2);
    t3=addPoly(p1,t1,p2,t2,p3);
    printf("\n\nResulatant Polynomial\n\n");
    display(p3,t3);
}
