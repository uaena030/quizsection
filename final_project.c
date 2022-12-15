#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//----------------------------------------------------------------宣告
int area[5] = {0};
int areasitutaion[6];
int dollars = 100,isc = 50,ipc = 100,dollarsum = 0,minutes = 15,price = 30; // orgin
int speedbooster = 0,pricebooster = 0,areabooster = 0; // boost count
int freechoice = 0;
int n=3,lottery[100][100],lotteryprice = 500,lotterynspace = 0;
int lotterynumber,cell;
int temp,temp2;
int boostersum,boosterqueue[15];
int mapsituation[8][8],playerlocation;
void mapinitialization();
void begin();
int beginbooster();
int booster(int *s,int *p, int *a);
void boosterchoose(int *speedboosteropen,int *priceboosteropen,int *areaboosteropen);
void actions(int isc,int ipc);
void actionsagain(int i);
void actionsdo(int i,int speedboosteropen,int priceboosteropen,int areaboosteropen);
void areacheck(int speedboosteropen,int priceboosteropen,int areaboosteropen);
void end();
int lotterybuild();
int lotterychoose();
void boosterjudge();
//----------------------------------------------------------------函式
void mapinitialization(){
    for(int i = 0;i < 8; i++){
        for(int j = 0;j < 8; j++){
            mapsituation[i][j] = 0;
        }
    }
    mapsituation[0][0] = 1; // 1 == P(player)
    playerlocation = 0;
    for(int i = 2;i <= 4; i++){
        temp = rand()%64;
        if(mapsituation[temp/8][temp%8]!=0){
            i--;
            continue;
        }
        mapsituation[temp/8][temp%8] = i; // 2 == M(Money) 3 == B(Booster) 4 == T(Task)
    }
}
void begin(){
    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n",dollars);
    printf("You need %d minutes to make a hotdog.\n",minutes);
    printf("The price of a hotdog is $%d.\n",price);
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n",speedbooster,pricebooster,areabooster);
    switch(boosterqueue[0]){
        case 1:
            printf("The oldest booster is speedbooster.");
            break;
        case 2:
            printf("The oldest booster is pricebooster.");
            break;
        case 3:
            printf("The oldest booster is areabooster.");
            break;
        default:
            printf("You have no booster now.");
    }
}
int beginbooster(){
    int boostersum = rand()%11+5;
    int temp;
    for(int i=0;i<boostersum;i++){
        temp = rand()%3+1;
        switch (temp){
            case 1:
                speedbooster++;
                boosterqueue[i] = 1;
                break;
            case 2:
                pricebooster++;
                boosterqueue[i] = 2;
                break;
            case 3:
                areabooster++;
                boosterqueue[i] = 3;
                break;
        }
    }
}
int booster(int *s,int *p, int *a){ // booster choose function
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
    }
    return 1;
}
void boosterchoose(int *speedboosteropen,int *priceboosteropen,int *areaboosteropen){
    int temp;
    printf("Open/Close boosters:\n");
    *speedboosteropen?printf("  [1] Speed booster (now open)\n"):printf("  [1] Speed booster (now close)\n");
    *priceboosteropen?printf("  [2] Price booster (now open)\n"):printf("  [2] Price booster (now close)\n");
    *areaboosteropen?printf("  [3] Area  booster (now open)\n"):printf("  [3] Area  booster (now close)\n");
    printf("  [4] Finish\n");
    printf("Enter the number(s): ");
    temp = booster(speedboosteropen,priceboosteropen,areaboosteropen);
    if(temp == 2){
        printf("Invalid input!!!!\n");
        boosterchoose(speedboosteropen,priceboosteropen,areaboosteropen);
    }
    else if(temp != 0){
        boosterchoose(speedboosteropen,priceboosteropen,areaboosteropen);
    }
}
void actions(int isc,int ipc){ // actions choose
    printf("Actions you can take for each area:\n");
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", isc,isc*2 ,isc*4 ,isc*8 );
    printf("  [3] Improve your hotdog flavor\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", ipc, ipc*2, ipc*4, ipc*8);
    printf("Enter the number(s): ");
    scanf("%d %d %d %d",&area[0],&area[1],&area[2],&area[3]);
    for(int i=0;i<4;i++){
        if(area[i] != 1 && area[i] != 2 && area[i] != 3){
            area[i] = 0;
        }
    }
    for(int i = 0;i<4;i++){
        if(area[i] == 0){
            actionsagain(i);
        }
    }


}
void actionsagain(int i){ // actions invalid,choose again
    printf("Invalid input!!!!\n");
    printf("Actions you can take at Area %d:\n", i+1);
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("  [3] Improve your hotdog flavor\n");
    printf("Enter the number(s): ");
    scanf("%d",&area[i]);
    if(area[i] != 1 && area[i] != 2 && area[i] != 3){
        actionsagain(i);
    }
}
void actionsdo(int i,int speedboosteropen,int priceboosteropen,int areaboosteropen){ // do area actions
    switch (area[i]){
        case 1:
            areasitutaion[i] = 0;
            sellhotdog:
            dollars += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
            dollarsum += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
            if(speedboosteropen){
                speedboosteropen = 2; // 開啟過了
            }
            if(priceboosteropen){
                priceboosteropen = 2; //開啟過了
            }
            break;
        case 2:
            if(dollars<isc){
                areasitutaion[i] = 1;
                goto sellhotdog;
            }
            else{
                if(minutes==1){
                    areasitutaion[i] = 2;
                    goto sellhotdog;
                }
                else{
                    areasitutaion[i] = 3;
                    minutes -=1;
                    dollars -=isc;
                    isc *= 2;
                    break;
                }
            }
            break;
        case 3:
            if(dollars<ipc){
                areasitutaion[i] = 1;
                goto sellhotdog;
            }
            else{
                areasitutaion[i] = 4;
                price += 10;
                dollars -= ipc;
                ipc *= 2;
                break;
            }
            break;
    }
    if(i == 3){
        if(areaboosteropen){
                dollars += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
                dollarsum += (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1);
                areabooster -= 1;
                for(int i=0;i<boostersum;i++){
                    if(boosterqueue[i] == 3){
                        temp = i;
                    }

                }
                for(int i=temp;i<boostersum-1;i++){
                    boosterqueue[i] = boosterqueue[i+1];
                }
                boostersum--;
            }
    }
}
void areacheck(int speedboosteropen,int priceboosteropen,int areaboosteropen){ // area check
    int temp;
    printf("Which result of the area you want to check?\n");
    printf("  [1] Area 1\n");
    printf("  [2] Area 2\n");
    printf("  [3] Area 3\n");
    printf("  [4] Area 4\n");
    areaboosteropen?printf("  [5] Area 5\n  [6] Done\n"):printf("  [5] Done\n");
    printf("Enter the number(s): ");
    scanf("%d",&temp);
    if(temp<0 || temp >6){
        printf("Invalid input!!!!\n");
        areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
    }
    switch (areasitutaion[temp-1]){
        case 0:
            printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
            printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
            break;
        case 1:
            printf("Can't you tell how poor you are?\n");
            printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
            printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
            printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
            break;
        case 2:
            printf("Do you want to travel through time?\n");
            printf("GO WORK!!\n");
            printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
            printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
            break;
        case 3:
            printf("You glimpse the secret of wind.\n");
            printf("Your hands can move faster now.\n");
            areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
            break;
        case 4:
            printf("You feel the soul of the ingredients.\n");
            printf("Your hotdogs are more appetizing now.\n");
            areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
            break;
        case 5:
            if(!areaboosteropen){
                break;
            }
            else{
                printf("You make %d hotdogs here!\n", (180/minutes)*(speedboosteropen?2:1));
                printf("You earn $%d!\n", (180/minutes)*price*(speedboosteropen?2:1)*(priceboosteropen?2:1));
            }
            areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
            break;
        case 6:
            if(!areaboosteropen){
                printf("Invalid input!!!!\n");
                areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
                break;
            }
            else{
                break;
            }
        default:
            printf("Invalid input!!!!\n");
            areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
            break;   
    }
}
void end(){ // check if end
    int temp;
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
            printf("We will miss you. Bye!\n");
            exit(0);
        default:
            printf("Invalid input!!!!\n");
            end();
    }
}
int lotterybuild(){ // lotterybuild
    int refresh;
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
        return 0; // 改成跳出
    }
    if(temp <= 0 || temp > n*n){
        printf("Invalid input!!!!\n");
        lotterybuild();
    }
    if(lottery[(temp-1)/n][(temp-1)%n] == 0){
        printf("Invalid input!!!!\n");
        lotterybuild();
    }
    if(freechoice == 0 && dollars < lotteryprice){
        printf("You have no money!\n");
        return 0; // 記得改成新的一天
    }
    else if(freechoice > 0){
        freechoice -= 1;
    }
    else{
        dollars -= lotteryprice;
        lotteryprice +=500;
    }
    lotterychoose(temp);
}
int lotterychoose(){ // do lottery choose
    lottery[(temp-1)/n][(temp-1)%n] = 0;
    cell = temp;
    lotterynumber = rand()%9+1;
    temp = cell;
    switch(lotterynumber){
        case 1:
            printf("Fortune, fortune! You get $%d!\n", price*100);
            dollars += price*100;
            lotterybuild();
            break;
        case 2:
            printf("You get an extra choice!\n");
            freechoice += 1;
            lotterybuild();
            break;
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
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
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
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
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
                temp = ((temp-1)/n)*n + temp2 + 1;
                printf("Another open on %d!\n", temp);
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
        case 6:
            if((temp - 1)%n == n-1){
                temp2 = 0;
            }
            else{
                temp2 = (temp-1)%n + 1;
            }
            if(lottery[(temp-1)/n][temp2] == 0){
                printf("Bad Luck :(\n");
            }
            else{
                temp = ((temp-1)/n)*n + temp2 + 1;
                printf("Another open on %d!\n", temp);
                lotterychoose(temp);
                break;
            }
            lotterybuild();
            break;
        case 7:
            printf("You get a speedbooster!!\n");
            speedbooster += 1;
            boostersum++;
            boosterjudge();
            lotterybuild();
            break;
        case 8:
            printf("You get a pricebooster!!\n");
            pricebooster += 1;
            boostersum++;
            boosterjudge();
            lotterybuild();
            break;
        case 9:
            printf("You get a areabooster!!\n");
            areabooster +=1;
            boostersum++;
            boosterjudge();
            lotterybuild();
            break;
    }
}
void boosterjudge(){
    if(boostersum>15){
        printf("Oops! Your boosters are too musch!");
        boostersum--;
        switch(boosterqueue[0]){
            case 1:
                printf("You lose a speedbooster!");
                speedbooster--;
                break;
            case 2:
                printf("You lose a pricebooster!");
                pricebooster--;
                break;
            case 3:
                printf("You lose a areabooster!");
                areabooster--;
                break;
        }
        for(int i=0; i<14;i++){
            boosterqueue[i] = boosterqueue[i+1];
        }
    }

}
void mapsystem(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            switch(mapsituation[i][j]){
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("P ");
                    break;
                case 2:
                    printf("M ");
                    break;
                case 3:
                    printf("B ");
                    break;
                case 4:
                    printf("T ");
                    break;
            }
        }
        printf("\n");
    }
    mapmoveinvalid:
    printf("Every step cost $25.\n");
    printf("  [1]up.\n");
    printf("  [2]down.\n");
    printf("  [3]left.\n");
    printf("  [4]right.\n");
    printf("  [5]quit.\n");
    printf("Enter the number(s) if you want to move: ");
    scanf("%d", &temp2);
    switch (temp2){
        case 1:
            mapsystem();
            break;
        case 2:
            mapsystem();
            break;
        case 3:
            mapsystem();
            break;
        case 4:
            mapsystem();
            break;
        case 5:
            break;
        default:
            printf("Invalid input!\n");
            goto mapmoveinvalid;
    }
}
//----------------------------------------------------------------
int  main(){
    srand(time(NULL));
    int temp,temp2; // orgin
    int speedboosteropen = 0,priceboosteropen = 0,areaboosteropen = 0; // boost open close
    for(int i = 0;i < n; i++){ //陣列初始化
        for(int j = 0;j < n; j++){
            lottery[i][j] = 1;
        }
    }
    mapinitialization();
    printf("Welcome, young boss!\n");
    while(1){
        dollarsum = 0;
        boostersum = beginbooster();
        begin();
        boosterchoose(&speedboosteropen,&priceboosteropen,&areaboosteropen);
        if(speedbooster == 0){
            speedboosteropen = 0;
        } 
        if(pricebooster == 0){
            priceboosteropen = 0;
        }
        if(areabooster == 0){
            areaboosteropen = 0;
        }
        actions(isc,ipc);
        for(int i=0;i<4;i++){
            actionsdo(i,speedboosteropen,priceboosteropen,areaboosteropen);
        }
        if(speedboosteropen == 2){
            speedboosteropen = 1;
            speedbooster -= 1;
            for(int i=0;i<boostersum;i++){
                if(boosterqueue[i] == 1){
                    temp = i;
                }

            }
            for(int i=temp;i<boostersum-1;i++){
                boosterqueue[i] = boosterqueue[i+1];
            }
            boostersum--;
        }
        if(priceboosteropen == 2){
            priceboosteropen = 1;
            pricebooster -= 1;
            for(int i=0;i<boostersum;i++){
                if(boosterqueue[i] == 2){
                    temp = i;
                }

            }
            for(int i=temp;i<boostersum-1;i++){
                boosterqueue[i] = boosterqueue[i+1];
            }
            boostersum--;
        }
        areasitutaion[4] = 5;
        areasitutaion[5] = 6;
        printf("Well done, you earn $%d today.\n",dollarsum);
        areacheck(speedboosteropen,priceboosteropen,areaboosteropen);
        mapsystem();
        end();
        lotterybuild();        
    }

}