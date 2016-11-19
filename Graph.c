/******INCLUDE********/

#include "Graph.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void addStudent(tstGraph *g, 
                const char *name, 
                const char *PLastName, 
                const char *MLastName, 
                const char *ID, 
                tenStuStatus status);

void printGraph(tstGraph *g);

void main(void){

    tstGraph* g;

    g=createGraph();

    addStudent(g,"Jordan Abel","Avalos","Bueno","A01227033",Active);
    addStudent(g,"Fabian","Galindo","Sanchez","A01226208",Active);
    addStudent(g,"Jorge Ernesto","Castaneda","Hernandez","A01225503",Active);

    printGraph(g);
}


void printGraph(tstGraph *g){


    tstAdjElem *tmp= g->adjListHead;
    printf("Address is:%p\n",tmp);

    while(tmp != NULL_PTR){
        printf("Node type is:%i\n", *((tenNodeType* )(tmp->vertex)) );
        printf("Name of student is%s\n", ((tstStudentV*)(tmp->vertex))->name );
        printf("ID of student is%s\n\n", ((tstStudentV*)(tmp->vertex))->ID );
        tmp=tmp->next;

    }
}

void* safeMalloc(size){

    void* tmp = malloc(size);
    if(tmp == NULL_PTR) exit(0);

    return tmp;
}

void addVertex(tstGraph *g, void *vertex){

    tstAdjElem *ptrVertex;
  
    //add Vertex to AdjList
    
    ptrVertex= (tstAdjElem*) safeMalloc(sizeof(tstAdjElem));
    ptrVertex->vertex= vertex;
    ptrVertex->next=NULL_PTR;
    ptrVertex->first_adj=NULL_PTR;
    
    if(g->adjListHead==NULL_PTR){ //Empty graph
        g->adjListHead = g->adjListTail = ptrVertex;
    }else{
        (g->adjListTail)->next = ptrVertex;
        g->adjListTail = ptrVertex;
    }

    g->V++;
    
}

void addStudent(tstGraph *g, 
                const char *name, 
                const char *PLastName, 
                const char *MLastName, 
                const char *ID, 
                tenStuStatus status){
    
    tstStudentV *tmp;
    char* str;
    
    //Allocate memory
    tmp = (tstStudentV*) safeMalloc(sizeof(tstStudentV));
    
    str = (char*) safeMalloc(strlen(name) 
                    + strlen(PLastName) 
                    + strlen(MLastName) 
                    + strlen(ID) + 4);


    //add parameters to node
    tmp->NodeType=student;

    strncpy(str,name,strlen(name)+1);
    tmp->name=str;

    str +=strlen(name)+1;

    strncpy(str,PLastName,strlen(PLastName)+1);
    tmp->PLastName=str;

    str += strlen(PLastName)+1;

    strncpy(str,MLastName,strlen(MLastName)+1);
    tmp->MLastName=str;

    str += strlen(MLastName)+1;

    strncpy(str,ID,strlen(ID)+1);
    tmp->ID=str;

    tmp->Status=status;

    //add vertex to graph

    printf("PLastName of student added is:%s\n",tmp->PLastName);
    addVertex(g, (void*) tmp);
         
}

tstGraph* createGraph(void){

    tstGraph* tmp;

    //Allocate graph basic structure
    tmp= malloc(sizeof(tstGraph));
    
    //Allocation failed for graph structure
    if(tmp == NULL_PTR) return NULL_PTR; //can use: exit(0);

    //if memory allocation was sucessfull, initialize all structures and return pointer
    tmp->V=0;
    tmp->E=0;

    tmp->adjListHead=NULL_PTR;
    tmp->adjListTail=NULL_PTR;
    
    return tmp;
}
