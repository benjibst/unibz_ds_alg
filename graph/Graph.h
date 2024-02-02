#include <stdbool.h>
#include "Queue.h"
#include "Stack.h"
#include "List.h"

#define SIZE 10000
#define INF 1000
#define NIL -1
#define WHITE 0
#define GREY 1
#define BLACK 2

typedef struct {
    int color;
    int start, end;
    int pred;
    int dist;
    List adj;
} Vertex;

typedef struct {
    bool isDag;
    int time;
    Vertex nodes[SIZE];
    int size;
    Stack ST;
} Graph;

void initGraph(Graph *g, int n);
void resetGraph(Graph *g);
void printGraph(Graph *g);
void addEdgeGraph(Graph *g, int i, int j);
void BFS(Graph *g, int s);
void DFS(Graph *g, int s);
void recDFS(Graph *g, int u);
void allDFS(Graph *g);
void topSort(Graph *g, int u);
bool topologicalSorting(Graph *g);
