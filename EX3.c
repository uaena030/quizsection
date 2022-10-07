#include <stdio.h>

int main(){
    int i1,i2,r,l[3];
    scanf("%d (!) %d R %d",&i1,&i2,&r);
    while(1){
        if(i1 % i2 == 0){
            break;
        }
        i1 += 1;
    }
    l[0] = r % 10;
    l[1] = (r % 100)/10;
    l[2] = r/100;
    printf("%d\n",i1);
    printf("%d%d%d",l[0],l[1],l[2]);
    return 0;


}