#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define I 32767
#define V 7
#define E 9

void printmcst(int t[][V-1]){
        printf("\n minimum cost spanning tree edges\n");
        int sum=0;
        for(int i=0;i<V-1;i++){
                int c=t[2][i];
                printf("\n [%d] --- [%d] cost=%d",t[0][i],t[1][i],c);
                sum=sum+c;
        }
        printf("\n the minimum cost spanning tree +%d\n",sum);
}
void union1(int u,int v,int s[]){
        if(s[u]<s[v]){
                s[u]+=s[v];
                s[v]=u;
        }
        else{
                s[v]+=s[u];
                s[u]=v;
        }
}
int find(int u,int s[]){
        int x=u;
        int v=0;
        while(s[x]>0){
                x=s[x];
        }
        return x;
}
void kruskalsmcst(int a[3][9]){
        int t[3][V-1];
        int visited[E]={0};
        int set[V+1]={-1,-1,-1,-1,-1,-1,-1,-1};
        int i=0;
        while(i<V-1){
                int min=I;
                int u=0,v=0,k=0;
                for(int j=0;j<E;j++){
                        if(visited[j]==0 && a[2][j]<min){
                                min=a[2][j];
                                u=a[0][j];
                                v=a[1][j];
                                k=j;
                        }
                }
                if(find(u,set)!=find(v,set)){
                        t[0][i]=u;
                        t[1][i]=v;
                        t[2][i]=min;
                        union1(find(u,set),find(v,set),set);
                        i++;
                }
                visited[k]=1;
        }
        printmcst(t);
}

int main(){
        int edge[3][9]={{1,1,2,2,3,4,4,5,5},
                        {2,6,3,7,4,5,7,6,7},
                        {25,5,12,10,8,16,14,20,18}};
        kruskalsmcst(edge);
        return 0;
}

