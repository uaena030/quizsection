#include <stdio.h>
int swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    int *ap,*bp;
    for(ap = &a[0];ap<&a[n];ap++){
        scanf("%d",ap);
    }
    for(bp = &b[0];bp<&b[n];bp++){
        scanf("%d",bp);
    }
    ap = &a[0];
    bp = &b[0];
    for(int i = 0;i<n;i++){
        swap(ap,bp);
        ap++;
        bp++;
    }
    ap = &a[0];
    bp = &b[0];
    printf("1st array: ");
    for(ap = &a[0];ap<&a[n];ap++){
        printf("%d ",*ap);
    }
    printf("\n");
    printf("2nd array: ");
    for(bp = &b[0];bp<&b[n];bp++){
        printf("%d ",*bp);
    }
}