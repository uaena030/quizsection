#include <stdio.h>

int main(){
    int a[16];
    for(int i=0; i<16; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<16; i++){
        printf("%d\t",a[i]);
        if((i+1)%4 == 0 && i != 0){
            printf("\n");
        }
    }
    for(int i=0; i<16; i+=4){
        printf("%d\t",a[i]+a[i+1]+a[i+2]+a[i+3]);
    }
    printf("\n");
    for(int i=0; i<4; i++){
        printf("%d\t",a[i]+a[i+4]+a[i+8]+a[i+12]);
    }
    printf("\n");
    printf("%d\t",a[0]+a[5]+a[10]+a[15]);
    printf("%d\t",a[3]+a[6]+a[9]+a[12]);
}