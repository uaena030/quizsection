#include <stdio.h>

int main(){
    int a,c,d,e;
    float b;
    scanf("%d %f %d/%d/%d",&a,&b,&c,&d,&e);
    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t$%.2f\t%02d\\%02d\\%04d",a,b,c,d,e);

}