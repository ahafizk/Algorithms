#include "graph.h"

void initialize_graph(graph *g, bool directed)
{
    int i;  //counter
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (i=1; i<MAXV;i++)
    {
        g->degree[i] = 0;
    }
    for (i=1;i<MAXV;i++)
    {
        g->edges[i] = NULL;
    }
}

/*
 * a typical graph file contains number of vertices, number of edges followed by
 *  vertices edges (x,y) in each line
*/
void read_graph(graph *g, bool directed)
{
    int i; //counter
    int m; //number of edges;
    int x,y; //vertices in edge (x,y)

    //initialize the graph
    initialize_graph(g,directed);
    //total number of vertices and edges for the graph
    cin>>(g->nvertices)>>m;

    //now read the edeges
    for (i=1; i<=m;i++)
    {
        cin>>x>>y;
        insert_edge(g,x,y,directed);
    }
}

//insert the edge information into the graph
int insert_edge(graph *g, int x, int y, bool directed)
{
    edgenode *p; //temporary pointer
    p = new edgenode; //allocating edgenode storage
    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p; //insert at the head of the list
    g->degree[x]++; //increment the degree of the node

    if (directed==false)
        insert_edge(g,y,x,true);
    else
        g->nedges++; //increment the edges

    return 1; // for success
}

void print_graph(graph *g)
{
    int i;
    edgenode *p;
    for (i=1;i<=g->nvertices;i++)
    {
        cout<<i<<" : ";
        p = g->edges[i];
        while(p!=NULL)
        {
            cout<<p->y<<" ";
            p->next;
        }
        cout << endl;
    }
}














































