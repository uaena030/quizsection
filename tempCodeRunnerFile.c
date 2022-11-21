#include <stdio,h>

int main(){
    int n=3,lotteryuse = 0,lottery[100][100],freechoice = 0,lotteryprice = 500,lottertype,temp;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            lottery[i][j] = 1;
        }
    }
    end:
        printf("Do you want to continue or exit?\n");
        printf("  [1] Continue\n");
        printf("  [2] Exit\n");
        printf("Enter the number(s): \n");
        scanf("%d",&temp);
        switch (temp){
            case 1:
                printf("You get one free choice.\n");
                freechoice = 1;
                break;
            case 2:
                printf("We will miss you. Bye!\n");
                return 0;
            default:
                printf("Invalid input!!!!\n");
                goto end;
        }

        for (int i = 0; i < n; i++){
            printf("+");
            for (int j = 0; j < n; j++){
                for (int k = 0; k < 4; k++) printf("-");
                printf("+");
            }
            printf("\n|");
            for (int j = 0; j < n; j++){
                if (lottery[i][j] == 0){
                    printf("  %c |",'x');
                } 
                else{
                    printf("  %d |", n*i+j+1);
                }
            }
            printf("\n");
        }
        printf("You can choose\n");
        freechoice? printf("  [number on cell] to open (- $0)\n"):printf("  [number on cell] to open (- $%d)\n", lotteryprice);
        printf("  [0] to continue the game\n");
        printf("Enter the number(s): \n");
        scanf("%d",&temp);
    }
    
}