#include <stdio.h>

int main(){
    int b,s,l,m,c,t; //b = blood s = strength l = level m = monster number c = continue

    printf("Welcome, Adventurer!\n");
    printf("Please enter blood, strength, level:\n");
    scanf("%d %d %d",&b,&s,&l);
    printf("You have %d blood and %d strength.\n",b,s);
    printf("Please choose which monster (1 to 4) you want to fight:\n");
    while(scanf("%d",&m)){
        if(m<=4 && m>=1){
            printf("You are fighting Monster %d!\n",m);
            switch(m){
                case 1:
                    if(s>l){
                        s++;
                        printf("You Win!\n");
                    }
                    else{
                        b -= (l+1);
                        printf("You Lose!\n");
                    }
                    break;
                case 2:
                    if(s>(l%2)+2){
                        s++;
                        printf("You Win!\n");
                    }
                    else{
                        b -= (l+2);
                        printf("You Lose!\n");
                    }
                    break;
                case 3:
                    if(l > 3){
                        t = l;
                    }
                    else{
                        t = 3;
                    }
                    if(s>t){
                        s++;
                        printf("You Win!\n");
                    }
                    else{
                        b -= (l+3);
                        printf("You Lose!\n");
                    }
                    break;
                case 4:
                    if(s>l*4){
                        s++;
                        printf("You Win!\n");
                    }
                    else{
                        b -= (l+4);
                        printf("You Lose!\n");
                    }
                    break;
            }
            printf("Do you want to go on your adventure (1: Yes; 0: No) ?:\n");
            scanf("%d", &c);
            if(c == 1){
                printf("You have %d blood and %d strength.\n",b,s);
                if(b<=0){
                    printf("You Dead. Bye!");
                    return 0;
                }
                else{
                    printf("Please choose which monster (1 to 4) you want to fight:\n");
                    continue;
                }
            }
            else{
                printf("We will miss you. Bye!");
                return 0;
            }
        }
        else{
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");
            printf("Do you want to go on your adventure (1: Yes; 0: No) ?:\n");
            scanf("%d", &c);
            if(c == 1){
                printf("You have %d blood and %d strength.\n",b,s);
                if(b<=0){
                    printf("You Dead. Bye!");
                    return 0;
                }
                else{
                    printf("Please choose which monster (1 to 4) you want to fight:\n");
                    continue;
                }
            }
            else{
                printf("We will miss you. Bye!");
                return 0;
            }
        }
    }


}