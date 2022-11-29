#include <stdio.h>
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int iaction();
int uaction();
void taction();
int daction();
int main(){
    int actionnum;
    printf("num of actions:\n");
    scanf("%d",&actionnum);
    char action[actionnum],ctemp;
    for(int i=0;i<actionnum;i++){
        scanf("%c",&ctemp);
        if(ctemp == ' ' || ctemp == '\n'){
            i--;
            continue;
        }
        action[i] = ctemp;
    }
    for(int i=0;i<actionnum;i++){
        switch(action[i]){
            case 'i':
                iaction();
                break;
            case 'u':
                uaction();
                break;
            case 't':
                taction();
                break;
            case 'd':
                daction();
                break;
            default:
                printf("INVALID ACTION\n");
                break;
        }
    }




}

int iaction(){
    int temp,temp2;
    printf("position to insert:\n");
    scanf("%d",&temp);
    if(temp<0 || temp>9){
        printf("INVALID POSITION\n");
        return 0;
    }
    printf("enter the value to insert:\n");
    scanf("%d",&temp2);
    for(int i=9; i>temp; i--){
        arr[i] = arr[i-1];
    }
    arr[temp] = temp2;
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int uaction(){
    int temp,temp2;
    printf("position to update:\n");
    scanf("%d",&temp);
    if(temp<0 || temp>9){
        printf("INVALID POSITION\n");
        return 0;
    }
    printf("enter the value to update:\n");
    scanf("%d",&temp2);
    arr[temp] = temp2;
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void taction(){
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int daction(){
    int temp;
    printf("position to delete:\n");
    scanf("%d",&temp);
    if(temp<0 || temp>9){
        printf("INVALID POSITION\n");
        return 0;
    }
    arr[temp] = 0;
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}