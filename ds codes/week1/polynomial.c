#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int d1,d2;
    printf("enter the degree of polynomial 1: ");
    scanf("%d",&d1);
    printf("enter the degree of polynomial 2: ");
    scanf("%d",&d2);
    int *p1,*p2;
    p1=(int*)malloc(d1+1*sizeof(int));
    p2=(int*)malloc(d2+1*sizeof(int));
    
    printf("please enter the coefficients: \n");
    for(int i=0;i<d1+1;i++){
        printf("please enter coefficient of %d: ",d1-i);
        scanf("%d",&p1[i]);
    }
    printf("the coefficients of polynomial 2: \n");
    for(int i=0;i<d2+1;i++){
        printf("please enter coefficient of %d: ",d2-i);
        scanf("%d",&p2[i]);
    }
    int k=0;
    if(d1>d2){
        int max=d1-d2;
        for(int i=max;i<d1+1;i++){
            p1[i]=p1[i]+p2[k];
            k++;
        }
        for(int i=0;i<d1+1;i++){
            printf("%d x(%d) ",p1[i],d1-i);
        }
    }
    else if(d2>d1){
        int max=d2-d1;
        for(int i=max;i<d2+1;i++){
            p2[i]=p2[i]+p1[k];
            k++;
        }
        for(int i=0;i<d2+1;i++){
            printf("%d x(%d) ",p2[i],d2-i);
        }
    }
    else if(d2==d1){
        for(int i=0;i<d2+1;i++){
            p2[i]=p2[i]+p1[i];
        }
        for(int i=0;i<d2+1;i++){
            printf("%d x(%d) ",p2[i],d2-i);
        }
        printf("\n");
    }
    int x,sum=0,d3,*p3;
    printf("please enter the degree of polynomial to evaluate: ");
    scanf("%d",&d3);
    printf("please enter the constant value of x: ");
    scanf("%d",&x);
    p3=(int*)malloc(d3+1*sizeof(int));
    printf("please enter the coefficients of polynomial to evaluate: \n");
    for(int i=0;i<d3+1;i++){
        printf("please enter coefficient of %d: ",d3-i);
        scanf("%d",&p3[i]);
    }
    for(int i=0;i<d3+1;i++){
        sum=sum+(pow(x,d3-i)*p3[i]);
    }
    printf("%d",sum);
    free(p1);
    free(p2);
    free(p3);
    return 0;

}