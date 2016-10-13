#ifndef BFS_ALG_H
#define BFS_ALG_H
#include<iostream>
#include<queue>
using namespace std;
#include "graph.h"
bool processed [MAXV+1]; //which vertices have been processed
bool discovered [MAXV+1]; //which vertices have been found
int parent[MAXV+1]; //discovery relation

void initialize_search(graph *g);
void bfs(graph *g, int start);
void process_edge(int x, int y);
void process_vertex_early(int v);
void process_vertex_late(int v);
#endif // BFS_ALG_H
