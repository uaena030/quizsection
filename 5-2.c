#include <stdio.h>

int main(){
    int n,temp,dec,decr,a = 1,b = 2,fibon[38],start = 0;
    char sum[38];
    scanf("%d",&n);
    fibon[0] = 1;
    fibon[1] = 2;
    for(int i = 2;a+b <= 100000000;i++){
        fibon[i] = a+b;
        temp = b;
        b = a+b;
        a = temp;
    }
    for(int i=0; i<n; i++){
        scanf("%d",&dec);
        decr = dec;
        start = 0;
        for(int j=0; j<38; j++){
            sum[j] = '0';
        }
        for(int j = 37;j >=0; j--){
            if(dec < fibon[j]){
                continue;
            }
            else{
                dec -= fibon[j];
                sum[j] = '1';
            }
        }
        printf("%d = ",decr);
        for(int j=37; j>=0; j--){
            if(sum[j] == '1'){
                start = 1;
            }
            if(start){
                printf("%c",sum[j]);
            }
        }
        printf(" (fib)\n");
    }


}