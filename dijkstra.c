#include<stdio.h>
#include<limits.h>
#include <stdbool.h>
#define V 6
int minDist(bool visited[],int dist[]){
    int min=INT_MAX,minInd;
    for(int i=0;i<V;i++){
        if(!visited[i] && dist[i]<=min){
            min=dist[i];
            minInd=i;
        }
    }
    return minInd;
}
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}
void dijkstra(int g[V][V],int s){
    int dist[V];
    bool visited[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[s] = 0;
    for(int i=0;i<V-1;i++){
        int u=minDist(visited,dist);
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(!visited[v] && g[u][v] && dist[u]!=INT_MAX && dist[v]>(dist[u]+g[u][v])){
                dist[v]=dist[u]+g[u][v];
            }
        }

    }
    printSolution(dist); 

}
int main(){
    int graph[V][V]={{0,2,0,4,0,0},{1,0,3,1,0,0},{0,3,0,0,0,0},{4,1,0,0,2,0},{0,0,0,2,0,2},{0,0,0,0,2,0}};
    dijkstra(graph,0);

}