#include <stdio.h>

int main(){
    int price = 30,dollar = 100;
    int n=3,lottery[100][100],freechoice = 0,lotteryprice = 500,lottertype,temp,temp2,lotterynspace = 0;
    int lotterynumber,cell;
    int speedbooster = 0,pricebooster = 0,areabooster = 0;
    int refresh = 0;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            lottery[i][j] = 1;
        }
    }
    end:
    printf("Do you want to continue or exit?\n");
    printf("  [1] Continue\n");
    printf("  [2] Exit\n");
    printf("Enter the number(s): ");
    scanf("%d",&temp);
    switch (temp){
        case 1:
            printf("You get one free choice.\n");
            freechoice += 1;
            break;
        case 2:
            printf("Speed booster: %d\n",speedbooster);
            printf("Price booster: %d\n",pricebooster);
            printf("Area booster: %d\n",areabooster);
            printf("Money: %d\n",dollar);
            printf("Free choice: %d\n",freechoice); //之後要刪掉
            printf("We will miss you. Bye!\n");
            return 0;
        default:
            printf("Invalid input!!!!\n");
            goto end;
    }
    lotteryagain:
    refresh = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            if(lottery[i][j] != 0){
                refresh = 0;
            }
        }
    }
    if(refresh == 1){
        lotteryprice = 500;
        n += 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                lottery[i][j] = 1;
            }
        }
    }
    lotterynspace = 0;
    for(int i = n*n; i>0;i /= 10){
        lotterynspace ++;
    }
    for (int i = 0; i < n; i++){
        printf("+");
        for (int j = 0; j < n; j++){
            for (int k = 0; k < lotterynspace+2; k++) printf("-");
            printf("+");
        }
        printf("\n|");
        for (int j = 0; j < n; j++){
            if (lottery[i][j] == 0){
                printf(" %*c |",lotterynspace,'x');
            } 
            else{
                printf(" %*d |",lotterynspace, n*i+j+1);
            }
        }
        printf("\n");
    }
    printf("+");
    for (int j = 0; j < n; j++){
        for (int k = 0; k < lotterynspace+2; k++) printf("-");
        printf("+");
    }
    printf("\n");
    printf("You can choose\n");
    freechoice? printf("  [number on cell] to open (- $0)\n"):printf("  [number on cell] to open (- $%d)\n", lotteryprice);
    printf("  [0] to continue the game\n");
    printf("Enter the number(s): ");
    scanf("%d",&temp);
    if(temp == 0){
        goto end; // 改成跳出
    }
    if(temp <= 0 || temp > n*n){
        printf("Invalid input!!!!\n");
        goto lotteryagain;
    }
    if(lottery[(temp-1)/n][(temp-1)%n] == 0){
        printf("Invalid input!!!!\n");
        goto lotteryagain;
    }
    if(freechoice == 0 && dollar < lotteryprice){
        printf("You have no money!\n");
        goto end; // 記得改成新的一天
    }
    else if(freechoice > 0){
        freechoice -= 1;
    }
    else{
        dollar -= lotteryprice;
        lotteryprice +=500;
    }
    extrachoice:
    lottery[(temp-1)/n][(temp-1)%n] = 0;
    cell = temp;
    lotterynumber = 0;
    while(temp != 0){
        lotterynumber = lotterynumber*10 + temp%10;
        temp /= 10;
    }
    temp = lotterynumber;
    lotterynumber = 0;
    for(int i = 0;temp != 0;i++){
        temp2 = temp%10;
        for(int j = 0;j < i;j++){
            temp2 *= 16;
        }
        temp /=10 ;
        lotterynumber += temp2;
    }
    lotterynumber %= 9;
    lotterynumber += 1;
    temp = cell;
    switch(lotterynumber){
        case 1:
            printf("Fortune, fortune! You get $%d!\n", price*100);
            dollar += price*100;
            goto lotteryagain;
        case 2:
            printf("You get an extra choice!\n");
            freechoice += 1;
            goto lotteryagain;
        case 3:
            if((temp - 1)/n == 0){
                temp2 = n-1;
            }
            else{
                temp2 = (temp-1)/n - 1;
            }
            if(lottery[temp2][(temp-1)%n] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = temp2*n + 1 + (temp-1)%n;
                printf("Another open on %d!\n", temp);
                goto extrachoice;
            }
            goto lotteryagain;
        case 4:
            if((temp - 1)/n == n-1){
                temp2 = 0;
            }
            else{
                temp2 = (temp-1)/n + 1;
            }
            if(lottery[temp2][(temp-1)%n] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = temp2*n + 1 + (temp-1)%n;
                printf("Another open on %d!\n", temp);
                goto extrachoice;
            }
            goto lotteryagain;
        case 5:
            if((temp - 1)%n == 0){
                temp2 = n-1;
            }
            else{
                temp2 = (temp-1)%n - 1;
            }
            if(lottery[(temp-1)/n][temp2] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = temp-1;
                printf("Another open on %d!\n", temp);
                goto extrachoice;
            }
            goto lotteryagain;
        case 6:
            if((temp + 1)%n == n-1){
                temp2 = 0;
            }
            else{
                temp2 = (temp-1)%n + 1;
            }
            if(lottery[(temp-1)/n][temp2] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = temp+1;
                printf("Another open on %d!\n", temp);
                goto extrachoice;
            }
            goto lotteryagain;
        case 7:
            printf("You get a booster!!\n");
            speedbooster += 1;
            goto lotteryagain;
        case 8:
            printf("You get a booster!!\n");
            pricebooster += 1;
            goto lotteryagain;
        case 9:
            printf("You get a booster!!\n");
            areabooster +=1;
            goto lotteryagain;
    }

}