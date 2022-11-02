#include <stdio.h>

int main(){
    int i,j,temp;
    scanf("%d %d",&i,&j);
    if(i>j){
        temp = j;
    }
    else if(j>i){
        temp = i;
    }
    else{
        printf("%d",i);
        return 0;
    }
    if(i == 0 || j == 0){
        if(i == 0){
            printf("%d",j);
        }
        else{
            printf("%d",i);
        }
    }
    for(int k = temp;k>0;k--){
        if(i%k == 0 && j%k == 0){
            printf("%d",k);
            return 0;
        }
    }




}