#include <stdio.h>
#include <ctype.h>

int main(){
    char i;
    int sum = 0;
    while((i = getchar()) != '\n' && i!= EOF){
        i = toupper(i);
        if(i == 'A' || i == 'I' || i == 'E' || i == 'L' || i == 'N' || i == 'O' || i == 'R' || i == 'S' || i == 'T' || i == 'U'){
            sum+=1;
        }
        else if(i == 'D' || i == 'G'){
            sum+=2;
        }
        else if(i == 'B' || i == 'C' || i == 'M' || i == 'P'){
            sum+=3;
        }
        else if(i == 'F' || i == 'H' || i == 'V' || i == 'W' || i == 'Y'){
            sum+=4;
        }
        else if(i == 'K'){
            sum+=5;
        }
        else if(i == 'J' || i == 'X'){
            sum+=8;
        }
        else if(i == 'Q' || i == 'Z'){
            sum+=10;
        }
    }
    printf("%d",sum);

}