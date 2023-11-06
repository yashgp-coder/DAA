#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 6
#define MAX_EDGES 100
struct Edges{
    int s,d,w;
};
struct graph{
    int v,e;
    struct Edges edges[MAX_EDGES];
};
void bellmanFord(struct graph g,int s){
    int v=g.v;
    int e=g.e;
    int dist[V];
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
    }
    dist[s]=0;
    for(int i=1;i<v;i++){
        for(int j=0;j<e;j++){
            int u=g.edges[j].s;
            int v=g.edges[j].d;
            int w=g.edges[j].w;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    for(int i=0;i<v;i++){
        printf("%d \t\t %d\n",i,dist[i]);
    }
}
int main(){
    int g[V][V]={{0,6,4,5,0,0},{0,0,0,0,-1,0},{0,-2,0,0,3,0},{0,0,-2,0,0,-1},{0,0,0,0,0,3},{0,0,0,0,0,0}};
    struct graph gr={V,0};
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(g[i][j]!=0){
                gr.edges[gr.e].s=i;
                gr.edges[gr.e].d=j;
                gr.edges[gr.e++].w=g[i][j];
            }
        }
    }
    bellmanFord(gr,0);
    return 0;
}