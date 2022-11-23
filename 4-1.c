#include <stdio.h>

int main(){
    long long int n,temp;
    int count = 0,numbers[10] = {0};
    scanf("%lld",&n);
    temp = n;
    while(temp != 0){
        temp/=10;
        count++;
    }
    int num[count];
    temp = n;
    for(int i=0;temp!=0;i++){
        num[i] = temp%10;
        temp/=10;
    }
    for(int i=0;i<count;i++){
        numbers[num[i]] += 1;
    }
    printf("0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0;i<10;i++){
        printf("%d ", numbers[i]);
    }





}