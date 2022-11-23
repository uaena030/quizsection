#include <stdio.h>

int main(){
    int a[5][5];//student score
    int average[5],total[5] = {0},temp;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            total[i] += a[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        average[i] = total[i]/5;
    }
    for(int i = 0; i < 5; i++){
        printf("%d %d %d\n",i+1,total[i],average[i]);
    }
}