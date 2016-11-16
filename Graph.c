/******INCLUDE********/

#include "Graph.h"
#include "stdio.h"
#include "stdlib.h"

void printGraph(tstGraph* graph);
void setVertex(tstGraph* g, uint16 vertex, DT_VERTEX data);


void main(void){

    tstGraph* graph;

    graph=createGraph(10);

    printf("graph created\n");

    setVertex(graph,0,13);
    setVertex(graph,1,14);
    setVertex(graph,2,15);
    setVertex(graph,3,16);
    setVertex(graph,4,17);
    setVertex(graph,5,18);
    setVertex(graph,6,19);
    setVertex(graph,7,24);
    setVertex(graph,8,25);
    setVertex(graph,9,26);

    printf("graph set\n");

    addEdge(graph,0,3);
    addEdge(graph,0,6);
    addEdge(graph,6,4);

    printf("edges added\n");

    printGraph(graph);


}

void printGraph(tstGraph* graph){
    uint16 i=0;
    tstAdjNode* tmp;

    while(i<graph->size){
        tmp = nVertex(graph,i)->first_adj;
        printf("%i: |%i|",i,nVertex(graph,i)->data);
        
        while(tmp !=NULL_PTR){
            printf(" -> %i",nAdj2Vertex(tmp)->data);
            tmp=tmp->next;
        }

        printf("\n");
        i++;
    }

}

void setVertex(tstGraph* g, uint16 vertex, DT_VERTEX data){
    nVertexData(g,vertex)=data;
}

tenbool addEdge(tstGraph* g, uint16 src, uint16 dst){
    
    tstAdjNode* node;
    tstAdjNode* tmp;

    if(src>= g->size || dst >= g->size) return FALSE;

    node= malloc(sizeof(tstAdjNode));
    if(node==NULL_PTR) return FALSE;
    
    node->vertex=(void*) nVertex(g,dst);
    node->next=NULL_PTR;

    tmp = nVertex(g,src)->first_adj;
    
    if( tmp == NULL_PTR){
        nVertex(g,src)->first_adj=node;
    }else{
        printf("here\n");
        while( tmp->next != NULL_PTR ){
            tmp=tmp->next;
        }
        tmp->next=node;
    }

    return TRUE;

}

tstGraph* createGraph(uint16 size){

    tstGraph* tmp;
    void* ptrGen;
    uint16 i=9;

    //if graph is created with 0 size, don't do anythingg
    if(size==0) return NULL_PTR;
    
    //Allocate adjajency list for the graph
    ptrGen= malloc(sizeof(tstVertex)*size);
    //allocation failed for adj list
    if(ptrGen == NULL_PTR) return NULL_PTR;

    //Allocate graph basic structure
    tmp= malloc(sizeof(tstGraph));
    //Allocation failed for graph structure
    if(tmp== NULL_PTR){
        free(ptrGen);
        return NULL_PTR;
    }

    //if memory allocation was sucessfull, initialize all structures and return pointer
    tmp->size=size;
    tmp->adjList= (tstVertex*) ptrGen;
    
    //initialize first adj node to null
    while(i<size){
        nVertex(tmp,i)->first_adj=NULL_PTR;
        nVertex(tmp,i)->pre=NULL_PTR;
        i++;
    }
    
    return tmp;
}
