#include <stdio.h>
int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int N,g,temp;
    while(scanf("%d",&N)){
        if(N == 0){
            break;
        }
        g = 0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                int ii = i,jj = j;
                if(jj>ii){
                    temp = jj;
                    jj = ii;
                    ii = temp;
                }
                g += gcd(ii,jj);
            }
        }
        printf("%d\n",g);
    }
}