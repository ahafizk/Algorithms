#include"bfs_alg.h"

void initialize_search(graph *g)
{
    int i; //counter
    for (i=1;i<=g->nvertices;i++)
    {
        processed[i] = discovered[i]= false;
        parent[i] = -1; // initialize without any parents
    }
}
void process_vertex_late(int v)
{

}
void process_vertex_early(int v)
{
    cout <<"processed vertex "<<v<<endl;
}
void process_edge(int x, int y)
{
    cout <<"processed edge ("<<x<<" , "<<y<<")\n";

}
void bfs(graph *g, int start)
{
    queue<int> q; //keep the vertex in the queue
    int v; //current vertex
    int y; //successor vertex
    edgenode *p;
//    init_queue(&q);
    q.push(start);
    discovered[start] = true;
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        process_vertex_early(v);
        processed[v] = true;
        p = g->edges[v];
        while(p!=NULL)
        {
            y = p->y;
            if ((processed[y]==false)||g->directed)
                process_edge(v,y);
            if (discovered[y] == false)
            {
                q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
}



























