#include <stdio.h>
#define I 32767
#define V 8

void print(int T[][V-2],int cost[V][V]){
        printf("Prims Minimum Cost Spanning Tree:\n");
        int sum=0;
        for(int i=0;i<V-2;i++){
                int c=cost[T[0][i]][T[1][i]];
                printf("%d -- %d cost: %d\n",T[0][i],T[1][i],c);
                sum+=c;}
        printf("Total minimum cost is %d\n",sum);
}

void prims(int cost[V][V],int n){
        int i,j,k,u,v,min=I;
        int near[8]={I,I,I,I,I,I,I,I};
        int T[2][6];
        for(i=1;i<V;i++){
                for(j=i;j<V;j++){
                        if(cost[i][j]<min){
                                min=cost[i][j];
                                u=i;
                                v=j;
                        }
                }
        }
        T[0][0]=u;
        T[1][0]=v;
        near[u]=0;
        near[v]=0;
        for(i=1;i<V;i++){
                if(near[i]!=0){
                        if(cost[i][u]<cost[i][v]){
                                near[i]=u;}
                        else{
                                near[i]=v;}
                }
        }
        for(i=1;i<n-1;i++){
                min=I;
                for(j=1;j<V;j++){
                        if(near[j]!=0 && cost[j][near[j]]<min){
                                min=cost[j][near[j]];
                                k=j;
                        }
                }
                T[0][i]=k;
                T[1][i]=near[k];
                near[k]=0;
                for(j=1;j<V;j++){
                        if(near[j]!=0 && cost[j][k]<cost[k][near[j]]){
                                near[j]=k;}
                }
        }
        print(T,cost);
}

int main(){
        int G[8][8]={
                {I,I,I,I,I,I,I,I},
                {I,I,25,I,I,I,5,I},
                {I,25,I,12,I,I,I,10},
                {I,I,12,I,8,I,I,I},
                {I,I,I,8,I,16,I,14},
                {I,I,I,I,16,I,20,18},
                {I,5,I,I,I,20,I,I},
                {I,I,10,I,14,18,I,I}
        };
        prims(G,7);
}