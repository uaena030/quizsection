#include <stdio.h>

int main(){
    int x,y,t = 0;
    scanf("%d:%d",&x,&y);
    if(x<0 || y<0 || x>=24 || y>=60){
        printf("Incorrect Input");
        return 0;
    }
    if(x>=12){
        t = 1;
    }
    if(t == 1){
        x = x-12;
        printf("%d:%02d PM",x,y);
    }
    else{
        if(x == 0){
            printf("12:%02d AM",y);
        }
        else{
            printf("%d:%02d AM",x,y);
        }
    }
    return 0;
}