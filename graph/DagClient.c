#include <stdio.h>
#include <stdbool.h>

#include "Graph.h"
#include "Client.h"

void dagTest() {

	printf("\n");
    printf("################################ \n");
    printf("########### dag test ########### \n");
    printf("################################ \n");

    bool isDag;

    Graph g;
    initGraph(&g, 8); // Initialize DAG with 8 vertices
					 //
    addEdgeGraph(&g, 0, 4);
    addEdgeGraph(&g, 1, 5);
    addEdgeGraph(&g, 1, 0);
    addEdgeGraph(&g, 2, 5);
    addEdgeGraph(&g, 2, 1);
    addEdgeGraph(&g, 3, 7);
    addEdgeGraph(&g, 3, 6);
    // addEdgeGraph(&g, 4, 5); // The graph is a DAG if and only if this is commented
    addEdgeGraph(&g, 5, 4);
    addEdgeGraph(&g, 6, 2);
    addEdgeGraph(&g, 6, 5);
    addEdgeGraph(&g, 7, 6);
    printGraph(&g);


    printf("-------------- allDFS -------------\n");
    resetGraph(&g);
    allDFS(&g);
    printGraph(&g);

    printf("-------------- Topological Sorting -------------\n");
    resetGraph(&g);
    isDag = topologicalSorting(&g);
    if (isDag) {
        printGraph(&g);
    }
}

