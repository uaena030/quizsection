#include <stdio.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}
int twowine(){
    int w1,w2,temp;
    printf("Now add two kinds of wines.\n");
    printf("Please Enter two types representing each wine: ");
    scanf("%d %d",&w1,&w2);
    if(w1 < w2){
        temp = w1;
        w1 = w2;
        w2 = temp;
    }
    temp = gcd(w1,w2);
    printf("The flavor level increased %d!\n",temp);
    return temp;
}
int shake(){    
    int temp,sum = 0;
    printf("Now shake.\n");
    printf("Please enter the power of a shake(0 to stop): ");
    while(scanf("%d",&temp)){
        if(temp == 0){
            break;
        }
        sum += temp;
        printf("Please enter the power of a shake(0 to stop): ");
    }
    printf("The flavor level increased %d!\n",sum);
    return sum;
}
int addjuice(){
    int temp;
    printf("Now add some juice.\n");
    printf("Please Enter flavor level of the juice: ");
    scanf("%d",&temp);
    printf("The flavor level increased %d!\n",temp);
    return temp;
}
int addco2(int level){
    int temp;
    printf("Now add some CO2.\n");
    printf("The current flavor level is %d.\n",level);
    printf("Please Enter power of CO2: ");
    scanf("%d",&temp);
    if(temp <= level/2){
        temp *= 2;
    }
    else if(temp > level/2 && temp <= level){
        temp *= 3;
    }
    else if(temp > level){
        temp = temp;
    }
    printf("The flavor level increased %d!\n",temp);
    return temp;
}
int pullintoglass(int level){
    int temp;
    printf("Finally, select a wine glass to pull your cocktail in.\n");
    printf("Please enter the number of wine glass(1 to 5): ");
    scanf("%d",&temp);
    switch(temp){
        case 1:
            printf("The price increased 10!\n");
            printf("Well done! The Price of this cocktail is %d!\n",10 + level);
            break;
        case 2:
            printf("The price increased 15!\n");
            printf("Well done! The Price of this cocktail is %d!\n",15 + level);
            break;
        case 3:
            printf("The price increased 17!\n");
            printf("Well done! The Price of this cocktail is %d!\n",17 + level);
            break;
        case 4:
            printf("The price increased 23!\n");
            printf("Well done! The Price of this cocktail is %d!\n",23 + level);
            break;
        case 5:
            printf("The price increased 40!\n");
            printf("Well done! The Price of this cocktail is %d!\n",40 + level);
            break;

    }
}
int main(){
    int level;
    printf("Let's make our first cocktail!\n");
    printf("Let's select the base wine!\n");
    printf("Please Enter flavor level of the base wine: ");
    scanf("%d",&level);
    printf("The flavor level is %d!\n",level);
    level += twowine();
    level += twowine();
    level += shake();
    level += addjuice();
    level += addco2(level);
    pullintoglass(level);
    printf("Let's make our second cocktail!\n");
    printf("Let's select the base wine!\n");
    printf("Please Enter flavor level of the base wine: ");
    scanf("%d",&level);
    printf("The flavor level is %d!\n",level);
    level += twowine();
    level += shake();
    level += addjuice();
    level += shake();
    level += addco2(level);
    level += twowine();
    level += addco2(level);
    level += addjuice();
    level += shake();
    level += twowine();
    level += shake();
    level += twowine();
    level += addjuice();
    level += addco2(level);
    level += shake();
    level += addco2(level);
    level += twowine();
    level += shake();
    level += addjuice();
    level += addjuice();
    level += twowine();
    level += twowine();
    level += addco2(level);
    level += shake();
    level += twowine();
    level += shake();
    level += twowine();
    level += shake();
    pullintoglass(level);
}