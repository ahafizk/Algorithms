#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

#define MAXV 1000 // maximum number of vertices
typedef struct edgenode
{
    int y;  //adjacency info  directed edge (x,y) by the edgenode y in x's adjacency list
    int weight; //edge weight, if any
    struct edgenode *next;  // next edge in list
} edgenode;

typedef struct
{
    edgenode *edges[MAXV+1]; //adjacency info
    int degree [MAXV+1]; //outdegree of each vertex
    int nvertices; //number of vertices in graph
    int nedges; //number of edges in graph
    bool directed; //is the graph directed?
}graph;

void initialize_graph(graph *g, bool directed);
void read_graph(graph *g , bool directed);
int insert_edge(graph *g, int x, int y, bool directed);
void print_graph(graph*g);























#endif // GRAPH_H
