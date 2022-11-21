#include <stdio.h>

int booster(int *s,int *p, int *a){
    int i;
    scanf("%d", &i);
    switch(i){
        case 1:
            if(*s == 1){
                *s = 0;
            }
            else{
                *s = 1;
            }
            break;
        case 2:
            if(*p == 1){
                *p = 0;
            }
            else{
                *p = 1;
            }
            break;
        case 3:
            if(*a == 1){
                *a = 0;
            }
            else{
                *a = 1;
            }
            break;
        case 4:
            return 0;
        default:
            return 2;
        return 1;
    }
}






int  main(){
    int play,dollars = 100,minutes = 15,price = 30,isc = 50,ipc = 100,action,dollarsum = 0,ct,temp;
    int speedbooster = 0,pricebooster = 0,areabooster = 0;
    int speedboosteropen = 0,priceboosteropen = 0,areaboosteropen = 0;
    printf("Welcome, young boss!\n");
    while(1){
        printf("Chop chop, It's dawn.\n");
        printf("You have %d dollars.\n",dollars);
        printf("You need %d minutes to make a hotdog.\n",minutes);
        printf("The price of a hotdog is $%d.\n",price);
        printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n",speedbooster,pricebooster,areabooster);
        if(speedbooster == 0){
            speedboosteropen = 0;
        } 
        if(pricebooster == 0){
            priceboosteropen = 0;
        }
        if(areabooster == 0){
            areaboosteropen = 0;
        }
        while(1){
            boostchooseagain:
            printf("Open/Close boosters:\n");
            speedboosteropen?printf("  [1] Speed booster (now open)\n"):printf("  [1] Speed booster (now close)\n");
            priceboosteropen?printf("  [2] Price booster (now open)\n"):printf("  [2] Price booster (now close)\n");
            areaboosteropen?printf("  [3] Area  booster (now open)\n"):printf("  [3] Area  booster (now close)\n");
            printf("  [4] Finish\n");
            printf("Enter the number(s): \n");
            temp = booster(&speedboosteropen,&priceboosteropen,&areaboosteropen);
            if(temp == 0){
                break;
            }
            else if(temp == 2){
                printf("Invalid input!!!!\n");
                goto boostchooseagain;
            }
        }


        
    }



}