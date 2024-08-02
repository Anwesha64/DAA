// help you to deleted the negative cycles.
#include <iostream>
#include <climits>
// #define I 460

void bellmanford(int graph[][3],int V,int E,int source){
    int dis[V];
    for(int i=0; i<V; i++)
        dis[i] = INT_MAX;
        dis[source] = 0;

    for(int i=1; i<V; i++){
        for(int j=0; j<E; j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int w = graph[j][2];
            if(dis[u] !=INT_MAX && dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }
    for (int i = 0; i < E; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];
        if (dis[u] != INT_MAX && dis[u] + w < dis[V]){
            std::cout << "Graph contains negative weight cycle" << std::endl;
        }
    }
 
    std::cout << "Vertex Distance from Source" << std::endl;
    for (int i = 0; i < V; i++)
        std::cout << char('A'+i) << "        "<< dis[i] << std::endl;

}

int main()
{
    int V = 6; // Number of vertices in graph
    int E = 7; // Number of edges in graph
 
    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    int graph[][3] = { { 3, 2, 6}, { 5, 3, 1 },
                       { 0, 1, 5 }, { 1, 5, -3 }, 
                       { 1, 2, -2 }, { 3, 4, -2 }, 
                       { 2, 4, 3 }};
 
    bellmanford(graph, V, E, 0);
    return 0;
}