#include <stdio.h>
#include <ctype.h>

int main(){
    char i;
    int vsum = 0,lsum = 0;
    int b = 1;
    while((i = getchar()) != '\n' && i!= EOF){
        i = toupper(i);
        if(i == ' '){
            lsum++;
            if(!b){
                lsum--;
            }
            b = 0;
        }
        else{
            b = 1;
            if(i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U'){
                vsum++;
            }
        }
    }
    printf("%d %d",vsum,lsum+1);
}