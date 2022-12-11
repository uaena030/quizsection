#include <stdio.h>
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int msize,temp;
    printf("What is the size of the matrix: ");
    scanf("%d",&msize);
    int matrix[msize][msize];
    printf("Please enter the matrix: ");
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
    printf("Enter the number of input data: ");
    scanf("%d",temp);
    for(int i=0; i<temp; i++){
        printf("What is the size of the matrix: ");
        scanf("%d",msize);
        int matrix[msize][msize];
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                scanf("%d",&matrix[i][j]);
            }
        }


    }
    printf("Enter the number of input data: ");
    scanf("%d",temp);
    for(int i=0; i<temp; i++){
        printf("the first matrix: ");

        scanf("%d",msize);
        for(int i=0; i<msize; i++){
            for(int j=0; j<msize; j++){
                scanf("%d",&matrix[i][j]);
            }
        }

        
    }
    

}