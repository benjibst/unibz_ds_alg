#include <stdio.h>
#include <stdbool.h>

#include "Graph.h"

char *colorname[] = {"W", "G", "B"};

void initGraph(Graph *g, int n) {
    g->isDag = true;
    g->time = 0;
    g->size = n;
    initStack(&(g->ST));

    for (int i = 0; i < n; i++) {
        g->nodes[i].color = WHITE;
        g->nodes[i].start = g->nodes[i].end = -1;
        g->nodes[i].pred = NIL;
        g->nodes[i].dist = INF;
        initList(&(g->nodes[i].adj), n);
    }
}

void resetGraph(Graph *g) {
    g->time = 0;
    g->isDag = true;
    for (int i = 0; i < g->size; i++) {
        g->nodes[i].color = WHITE;
        g->nodes[i].start = g->nodes[i].end = -1;
        g->nodes[i].pred = NIL;
        g->nodes[i].dist = INF;
    }
}

void printGraph(Graph *g) {
    printf("\n--------- Graph: -------\n");
    for (int i = 0; i < g->size; i++) {
        printf("[%2d, %2d, %2d, %s, (%2d/%2d)]",
            i,
            g->nodes[i].pred,
            g->nodes[i].dist,
            colorname[g->nodes[i].color],
            g->nodes[i].start,
            g->nodes[i].end);
        if (!isEmptyList(&(g->nodes[i].adj))) {
            printList(&(g->nodes[i].adj));
        } else {
            printf("\n");
        }
    }
    printf("------------------------\n");
}

void addEdgeGraph(Graph *g, int i, int j) {
    if (i >= 0 && i < g->size && j >= 0 && j < g->size) {
        insertList(&(g->nodes[i].adj), j);
    }
}
void BFS(Graph *g, int s) {
    Queue queue;
    initQueue(&queue);
    g->nodes[s].color = GREY;
    g->nodes[s].dist = 0;
    enqueue(&queue,s);
    while (!isEmptyQueue(&queue)){
        int curr = dequeue(&queue);
        printf("Visiting: %d with %d children",curr,g->nodes[curr].adj.count);
        for (int j = 0; j < g->nodes[curr].adj.count; ++j) {
            int currchild = valueList(&g->nodes[curr].adj,j);
            if (g->nodes[currchild].color == WHITE){
                g->nodes[currchild].color = GREY;
                g->nodes[currchild].dist = g->nodes[curr].dist + 1;
                g->nodes[currchild].pred = curr;
                enqueue(&queue,currchild);
        }
        printf("\n");
    }
    printGraph(g);
}

// DFS
void DFS(Graph *g, int s) {
  	// to fill
}

// all DFS and recursive DFS
void recDFS(Graph *g, int u) {
    // to fill
}

void allDFS(Graph *g) {
    // to fill
}

// topological sorting
void topSort(Graph *g, int u) {
    // to fill
}


bool topologicalSorting(Graph *g) {
    resetGraph(g);
    initStack(&(g->ST));
    g->isDag = true;

    for (int i = 0; i < g->size; i++) {
        if (g->nodes[i].color == WHITE) {
            topSort(g, i);
        }
    }

    if (g->isDag) {
        printf("Topological Sorting: ");
        while (!isEmptyStack(&(g->ST))) {
            int v = popStack(&(g->ST));
            printf("%d ", v);
        }
        printf("\n");
        return true;
    } else {
        printf("!!! The graph is not a DAG, Topological Sorting is not possible!!!\n");
        return false;
    }
}

