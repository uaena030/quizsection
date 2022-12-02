#include <stdio.h>

int Ni(int a){
    if(a == 0){
        return 1;
    }
    return a*Ni(a-1);
}
int Fi(int a){
    if(a == 0){
        return 0;
    }
    else if(a == 1){
        return 1;
    }
    return Fi(a-1)+Fi(a-2);
}
long long int Ci(long long int n,long long int k){
    if(k == 0 || k == n){
        return 1;
    }
    return Ci(n-1,k)+Ci(n-1,k-1);
}
long long int Xi(long long int x,long long int y,long long int m){
    if(y == 1){
        return x%m;
    }
    else if(y%2==0){
        return ((Xi(x,y/2,m)%m)*(Xi(x,y/2,m)%m))%m;
    }
    else{
        return ((x%m)*(Xi(x,y-1,m)%m))%m;
    }

    
}
int main(){
    int times,query,temp,output;
    long long int temp2,temp3,temp4,loutput;
    printf("How many queries do you want: ");
    scanf("%d",&times);
    for(int i=0; i<times; i++){
        printf("Which type of query do you want: ");
        scanf("%d",&query);
        switch(query){
            case 1:
                printf("Please enter N: ");
                scanf("%d",&temp);
                output = Ni(temp);
                printf("%d\n",output);
                break;
            case 2:
                printf("Please enter i: ");
                scanf("%d",&temp);
                output = Fi(temp);
                printf("%d\n",output);
                break;
            case 3:
                printf("Please enter n and k: ");
                scanf("%lld %lld",&temp2,&temp3);
                loutput = Ci(temp2,temp3);
                printf("%lld\n",loutput);
                break;
            case 4:
                printf("Please enter x, y and m: ");
                scanf("%lld %lld %lld",&temp2,&temp3,&temp4);
                loutput = Xi(temp2,temp3,temp4);
                printf("%lld\n",loutput);
                break;
        }
    }

}