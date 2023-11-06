#include <stdio.h>
#include <limits.h>
#define V 5
int minkey(int key[], int mstSet[]){
    int min=INT_MAX,minInd;
    for(int i=0;i<V;i++){
        if(mstSet[i]==0 && key[i]<min){
            min = key[i];
            minInd=i;
        }
    }
    return minInd;
}
void primeAlgo(int g[V][V]){
    int key[V];
    int mstSet[V];
    int parent[V];
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        mstSet[i] = 0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++){
        int u=minkey(key,mstSet);
        mstSet[i]=1;
        for(int j=0;j<V;j++){
            if(g[u][j]!=0 && mstSet[j]==0 && g[u][j]<key[j]){
                key[j]=g[u][j];
                parent[j]=u;
            }

        }
    }
    for(int i=1;i<V;i++){
        printf("%d-%d\t %d\n",parent[i],i,key[i]);
    }

}
int main (){
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primeAlgo(graph);
    return 0;
}