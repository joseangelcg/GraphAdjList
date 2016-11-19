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

void addCourse(tstGraph *g,
                char *CourseID,
                char *name);

void addProfessor(tstGraph *g,
                char *name,
                char *PLastName,
                char *MLastName,
                char *ID);

void addDegree(tstGraph *g,
                char *name,
                char *acronym);

void addArea(tstGraph *g,
                char *name);

void addCampus(tstGraph *g,
                char *name,
                char *location);

void addExtra(tstGraph *g,
                char *name);


void printGraph(tstGraph *g);

void main(void){

    tstGraph* g;

    g=createGraph();

    addStudent(g,"Jordan Abel","Avalos","Bueno","A01227033",Active);
    addStudent(g,"Fabian","Galindo","Sanchez","A01226208",Active);
    addStudent(g,"Jorge Ernesto","Castaneda","Hernandez","A01225503",Active);
    addProfessor(g,"Martin","Sinsel","Gonzalez","L01227584");
    addCourse(g,"TC1207","Matematicas IV");

    printGraph(g);
}


void printGraph(tstGraph *g){


    tstAdjElem *tmp= g->adjListHead;
    printf("Number of V::%i\n",g->V);
    printf("Number of E::%i\n",g->E);

    while(tmp != NULL_PTR){
        switch(getNodeType(tmp)){

            case student:
                printf("Name of student is%s\n", getStudentVertex(tmp)->name );
                printf("ID of student is%s\n\n", getStudentVertex(tmp)->ID );
                break;

            case professor:
                printf("Name of professor is%s\n", getProfessorVertex(tmp)->name );
                printf("ID of professor is%s\n\n", getProfessorVertex(tmp)->ID );
                break;

            case course:
                printf("Name of course is:%s\n",getCourseVertex(tmp)->name);
                printf("Course ID is:%s\n\n",getCourseVertex(tmp)->CourseID);
                break;
        }

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

    addVertex(g, (void*) tmp);
         
}

void addCourse(tstGraph *g,
                char *CourseID,
                char *name){
    tstCourseV *tmp;
    char* str;
    
    //Allocate memory
    tmp = (tstCourseV*) safeMalloc(sizeof(tstCourseV));
    
    str = (char*) safeMalloc(strlen(CourseID) 
                    + strlen(name)+2); 


    //add parameters to node
    tmp->NodeType=course;

    strncpy(str,CourseID,strlen(CourseID)+1);
    tmp->CourseID=str;

    str +=strlen(CourseID)+1;

    strncpy(str,name,strlen(name)+1);
    tmp->name=str;

    //add vertex to graph

    addVertex(g, (void*) tmp);
}

void addProfessor(tstGraph *g,
                char *name,
                char *PLastName,
                char *MLastName,
                char *ID){

    tstProfessorV *tmp;
    char* str;
    
    //Allocate memory
    tmp = (tstProfessorV*) safeMalloc(sizeof(tstProfessorV));
    
    str = (char*) safeMalloc(strlen(name) 
                    + strlen(PLastName) 
                    + strlen(MLastName) 
                    + strlen(ID) + 4);


    //add parameters to node
    tmp->NodeType=professor;

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

    

    //add vertex to graph

    addVertex(g, (void*) tmp);
        
}

void addDegree(tstGraph *g,
                char *name,
                char *acronym){

    tstDegreeV *tmp;
    char* str;
    
    //Allocate memory
    tmp = (tstDegreeV*) safeMalloc(sizeof(tstDegreeV));
    
    str = (char*) safeMalloc(strlen(name) 
                    + strlen(acronym)+2); 


    //add parameters to node
    tmp->NodeType=degree;

    strncpy(str,name,strlen(name)+1);
    tmp->name=str;

    str +=strlen(name)+1;

    strncpy(str,acronym,strlen(acronym)+1);
    tmp->acronym=str;

    //add vertex to graph

    addVertex(g, (void*) tmp);
        
}

void addArea(tstGraph *g,
                char *name){
    tstAreaV *tmp;
    char* str;
    
    //Allocate memory
    tmp = (tstAreaV*) safeMalloc(sizeof(tstAreaV));
    
    str = (char*) safeMalloc(strlen(name) + 1); 


    //add parameters to node
    tmp->NodeType=area;

    strncpy(str,name,strlen(name)+1);
    tmp->name=str;

    //add vertex to graph

    addVertex(g, (void*) tmp);
}

void addCampus(tstGraph *g,
                char *name,
                char *location){
    
    tstCampusV *tmp;
    char* str;
    
    //Allocate memory
    tmp = (tstCampusV*) safeMalloc(sizeof(tstCampusV));
    
    str = (char*) safeMalloc(strlen(name) 
                    + strlen(location)+2); 


    //add parameters to node
    tmp->NodeType=campus;

    strncpy(str,name,strlen(name)+1);
    tmp->name=str;

    str +=strlen(name)+1;

    strncpy(str,location,strlen(location)+1);
    tmp->location=str;

    //add vertex to graph

    addVertex(g, (void*) tmp);
}

void addExtra(tstGraph *g,
                char *name){
    tstExtraV *tmp;
    char* str;
    
    //Allocate memory
    tmp = (tstExtraV*) safeMalloc(sizeof(tstExtraV));
    
    str = (char*) safeMalloc(strlen(name) + 1); 


    //add parameters to node
    tmp->NodeType=area;

    strncpy(str,name,strlen(name)+1);
    tmp->name=str;

    //add vertex to graph

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
