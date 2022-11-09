#include <stdio.h>
#include <ctype.h>

int main(){
    char i,a,A;
    int bytescount = 0,lowercount = 0,uppercount = 0,dcount = 0,wcount = 0,linecount = 0;
    int alph[26],alphsum = 0;
    float rate;
    for(int i = 0;i<26;i++){
        alph[i] = 0;
    }
    while((i = getchar()) != EOF){
        bytescount += 1;
        if(i == '\n'){
            lincount += 1;
        }
        else if(i == ' '){
            wcount += 1;
        }
        else if(i <= 'Z' && i >= 'A'){
            alph[i - 'A'] += 1;
            uppercount += 1;
        }
        else if(i <= 'a' && i >= 'z'){
            alph[i - 'a'] += 1;
            lowercount += 1;
        }
        else if(i >= '0' && i <= '9'){
            dcount += 1;
        }
    }
    printf("Bytes Count: %d\n",bytescount);
    printf("Lowercase Count: %d\n",lowercount);
    printf("Uppercase Count: %d\n",uppercount);
    printf("Digit Count: %d\n",digitcount);
    printf("Whitespace Count: %d\n",wcount);
    printf("Line Count: %d\n",linecount);
    for(i=0; i<26; i++){
        alphsum += alph[i];
    }
    for(i = 0; i <26;i++){
        A = 'A' + i;
        a = tolower(a);
        rate = alph[i]/alphsum;
        printf("%c/%c: %d,%d",a,A,alph[i],rate);
    }
}

