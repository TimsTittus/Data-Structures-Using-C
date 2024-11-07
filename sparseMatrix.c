#include <stdio.h>
int main(){
    int mat[10][10],m,n,k=0;
    printf("Enter the order of Matrix: ");
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("Enter element [%d][%d]: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n\nMATRIX\n\n");
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    int nonZero=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (mat[i][j]!=0){
            nonZero++;
            }
        }
    }
    int sparse[nonZero][3];
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (mat[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=mat[i][j];
                k++;
            }
        }
    }
    printf("\n\nSPARSE MATRIX\n\n");
    printf("ROWS\t|COLUMNS\t|VALUES\t\n");
    printf("_______________________________\n\n");
    for(int i=0; i<nonZero;i++){
        printf("%d\t|%d\t\t|%d\t",sparse[i][0],sparse[i][1],sparse[i][2]);
        printf("\n");
    }
 }