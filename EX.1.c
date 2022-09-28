#include <stdio.h>

int main()
{
    int sum, i;
    scanf("%d",&i);
    sum = i/100;
    printf("100g bags: %d\n",sum);
    i = i%100;
    sum = i/50;
    printf("50g bags: %d\n",sum);
    i = i%50;
    sum = i/10;
    printf("10g bags: %d\n",sum);
    i = i%10;
    sum = i/5;
    printf("5g bags: %d\n",sum);
    i = i%5;
    sum = i;
    printf("1g bags: %d",sum);
}