#include <stdio.h>
#include "Graph.h"
#include "Client.h"

void graphTest() {

	printf("\n");
    printf("################################## \n");
    printf("########### graph test ########### \n");
    printf("################################## \n");

    Graph g;

    // Building the graph
    initGraph(&g, 8); // Initialize graph with 8 vertices
    addEdgeGraph(&g, 0, 4);
    addEdgeGraph(&g, 1, 5);
    addEdgeGraph(&g, 1, 0);
    addEdgeGraph(&g, 2, 5);
    addEdgeGraph(&g, 2, 1);
    addEdgeGraph(&g, 3, 7);
    addEdgeGraph(&g, 3, 6);
    addEdgeGraph(&g, 4, 1);
    addEdgeGraph(&g, 5, 4);
    addEdgeGraph(&g, 6, 2);
    addEdgeGraph(&g, 6, 5);
    addEdgeGraph(&g, 7, 3);
    addEdgeGraph(&g, 7, 6);
    printGraph(&g);

    printf("-------------- BFS(3) -------------\n");
    resetGraph(&g);
    BFS(&g, 3);
    printGraph(&g);

    printf("-------------- DFS(3) -------------\n");
    resetGraph(&g);
    DFS(&g, 3);
    printGraph(&g);

    printf("-------------- recDFS(3) -------------\n");
    resetGraph(&g);
    recDFS(&g, 3);
    printGraph(&g);

    printf("-------------- allDFS -------------\n");
    resetGraph(&g);
    allDFS(&g);
    printGraph(&g);

}
