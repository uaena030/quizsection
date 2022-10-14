#include <stdio.h>

int main(){
    int x,a;
    scanf("%d",&x);
    switch (x/10) {
        case 10:
            if(x>100){
                printf("error");
                break;
            }
        case 9:
            printf("A");
            break;
        case 8:
        case 7:
            if(x>=75){
                printf("B");
                break;
            }
        case 6:
            printf("C");
            break;
        default:
            if(x<0 || x>100){
                printf("error");
            }
            else{
                printf("D");
            }

    }


}