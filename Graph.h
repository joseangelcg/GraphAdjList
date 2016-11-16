#ifndef _GRAPH_H
#define _GRAPH_H

/*********INCLUDES***********/

#include "types.h"
/*********DEFINES**********/

#define DT_VERTEX   uint16
#define MAX_VERTEX  65535
#define NULL_PTR    NULL

/***********MACROS***********/
#define nVertex(g,v)        (g->adjList + v)
#define nVertexData(g,v)    (g->adjList + v)->data

#define nAdj2Vertex(node)   ((tstVertex*)(node->vertex))
/**********TYPEDEFS**************/

typedef struct node{

    struct node* next;
    void* vertex; //pointer to adjacent element

}tstAdjNode;

typedef struct v{
    
    DT_VERTEX data;
    tstAdjNode* first_adj;
    struct v* pre;

}tstVertex;

typedef struct graph{
    
    uint16 size;
    tstVertex* adjList;
    
}tstGraph;

/*******FUNCTION PROTOTYPES************/

tstGraph* createGraph(uint16 size);
tenbool addEdge(tstGraph* g,uint16 src, uint16 dst);

#endif //_GRAPH_H
