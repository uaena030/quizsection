#include <stdio.h>

int main(){
    int temp,temp2,lotterynumber = 0;
    temp = 9;
    for(int i = 0;temp != 0;i++){
        temp2 = temp%10;
        for(int j = 0;j < i;j++){
            temp2 *= 16;
        }
        temp /=10 ;
        lotterynumber += temp2;
    }
    lotterynumber %= 9;
    lotterynumber++;
    printf("%d\n",lotterynumber);
}