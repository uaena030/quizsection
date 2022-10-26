#include <stdio.h>

int main(){
    int play,dollars = 100,minutes = 15,price = 30,isc = 50,ipc = 100,action,dollarsum = 0,ct;
    printf("Welcome, young boss!\n");
    while(1){
        printf("Chop chop, It's dawn.\n");
        for(int i=1; i<=4; i++){
            printf("You are at Area %d.\n",i);
            printf("You have %d dollars.\n",dollars);
            printf("You need %d minutes to make a hotdog.\n",minutes);
            printf("The price of a hotdog is $%d.\n",price);
            actionagain:
            printf("Please choose which action you want to take:\n");
            printf("[1] Sell the hotdogs (+ $%d)\n",(180/minutes)*price);
            printf("[2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n",isc);
            printf("[3] Improve your hotdog flavor (- $%d / + $10 for each hotdog) \n",ipc);
            printf("Enter the number:\n");
            scanf("%d",&action);
            switch(action){
                case 1:
                    sellhotdog:
                    printf("You make %d hotdogs here!\n",180/minutes);
                    printf("You earn $%d!\n",(180/minutes)*price);
                    dollars += (180/minutes)*price;
                    dollarsum += (180/minutes)*price;
                    break;
                case 2:
                    if(dollars<isc){
                        printf("Can't you tell how poor you are?\n");
                        printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                        goto sellhotdog;
                    }
                    else{
                        if(minutes==1){
                            printf("Do you want to travel through time?\n");
                            printf("GO WORK!! \n");
                            goto sellhotdog;
                        }
                        else{
                            printf("You glimpse the secret of wind.\n");
                            printf("Your hands can move faster now.\n");
                            minutes -=1;
                            dollars -=isc;
                            isc *= 2;
                            break;
                        }
                    }
                case 3:
                    if(dollars<ipc){
                        printf("Can't you tell how poor you are?\n");
                        printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                        goto sellhotdog;
                    }
                    else{
                        printf("You feel the soul of the ingredients.\n");
                        printf("Your hotdogs are more appetizing now.\n");
                        price += 10;
                        dollars -= ipc;
                        ipc *= 2;
                        break;
                    }
                default:
                    printf("Invalid input!!!!\n");
                    goto actionagain;
            }



        }
        printf("Well done, you earn $%d today.\n",dollarsum);
        dollarsum = 0;
        ctagain:
        printf("Do you want to continue or exit?\n");
        printf("\t[1] Continue\n");
        printf("\t[2] Exit\n");
        printf("Enter the number:\n");
        scanf("%d",&ct);
        if(ct == 1){
            continue;
        }
        else if(ct == 2){
            printf("We will miss you. Bye!");
            return 0;
        }
        else{
            printf("Invalid input!!!!\n");
            goto ctagain;
        }

    }
}