#include <stdio.h>
int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int n,a,b,temp,check = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        check = 0;
        if(a < b){
            for(int j=0;j<=b-1;j++){
                if((a*j)%b == 1){
                    check = 1;
                    printf("multiplicative inverse is %d\n",j);
                    break;
                }
            }
            if(check == 0){
                printf("Inverse doesn't exist\n");
            }
        }
        else if(a%b == 0){
            printf("Inverse doesn't exist\n");
        }
        else{
            for(int j=0;j<=b-1;j++){
                if((a*j)%b == 1){
                    check = 1;
                    printf("multiplicative inverse is %d\n",j);
                    break;
                }
            }

        }


    }
}