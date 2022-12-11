#include <stdio.h>
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int msize,temp,check = 0;
    scanf("%d",&msize);
    int matrix[100][100];
    for(int i=0; i<msize; i++){
        for(int j=0; j<msize; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0; i<msize; i++){
        for(int j=i+1; j<msize; j++){
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
    for(int i=0; i<msize; i++){
        for(int j=0; j<msize/2; j++){
            swap(&matrix[i][j], &matrix[i][msize-j-1]);
        }
    }
    for(int i=0; i<msize; i++){
        for(int j=0; j<msize; j++){
            printf("%d ",matrix[i][j]);
        }
    }
    printf("\n");
    scanf("%d",&temp);
    for(int i=0; i<temp; i++){
        check = 0;
        scanf("%d",&msize);
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                if(i == j){
                    continue;
                }
                else{
                    if(matrix[i][j] != matrix[msize - i - 1][msize - j - 1]){
                        check = 1;
                    }
                }
            }
        }
        if(check){
            printf("The matrix is not symmetric!\n");
        }
        else{
            printf("The matrix is symmetric!\n");
        }
    }
    scanf("%d",&temp);
    int fmatrix[100][100],smatrix[100][100],nmatrix[100][100],sum;
    for(int i=0; i<temp; i++){
        scanf("%d",&msize);
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                scanf("%d",&fmatrix[i][j]);
            }
        }
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                scanf("%d",&smatrix[j][i]);
            }
        }
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                sum = 0;
                for(int k=0; k<msize; k++){
                    if(fmatrix[i][k] == 0 || smatrix[j][k] == 0){
                        sum += 0;
                    }
                    else{
                        sum += fmatrix[i][k]*smatrix[j][k];
                    }
                }
                nmatrix[i][j] = sum;
            }
            
        }
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                printf("%d ",nmatrix[i][j]);
            }
        }
        printf("\n");
    }
    

}