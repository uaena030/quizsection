#include<stdio.h>

int main(){
    int a,b;
    float c,d;
    scanf("%d + %d =",&a,&b);
    printf("%d\n",a + b);
    scanf("%d - %d =",&a,&b);
    printf("%d\n",a - b);
    scanf("%d * %d =",&a,&b);
    printf("%d\n",a * b);
    scanf("%f / %f =",&c,&d);
    printf("%.2f\n",c / d);
    return 0;
}