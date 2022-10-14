#include <stdio.h>

int main(){
    int N,botm,temp;
    scanf("%d",&N);
    temp = N*2-1;
    for(int i=0;i<N;N--){
        for(int j=0;j<N-1;j++){
            printf(" ");
        }
        for(int k = 0;k<temp - 2*(N-1);k++){
            printf("*");
        }        
        printf("\n");
    }



}