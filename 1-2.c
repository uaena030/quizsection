#include <stdio.h>

int main(){
    int a,c,d,e;
    float b;
    scanf("%d %f %d/%d/%d",&a,&b,&c,&d,&e);
    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t$%.2f\t%d\\%d\\%d",a,b,c,d,e);
    // printf("%*s %*s %*s\n","Item","Unit","Purchase");
    // printf("%*s %*s %*s\n"," ","Price","Date");
    // printf("%*d %*.2f  %d\\%d\\%d",a,b,c,d,e);

}