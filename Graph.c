/******INCLUDE********/

#include "Graph.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Queue.h"
/******       VERTEX FUNCTIONS        ******/
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
/*          EDGE FUNCTIONS PROTOTYPES       */

tstStu_Cour* createStu_Cour( tenCourseState state,
                uint8 grade,
                uint8 semester);

tstStu_Deg* createStu_Deg(
                uint8 initSemester,
                uint8 finalSemester,
                tenStu_DegStatus state);

tstStu_Camp* createStu_Camp(
                tenbool native);

tstStu_Extra* createStu_Extra(
                tenExtraState state,
                uint8 semester);

tstProf_Course* createProf_Course(
                char* period);

tstProf_Campus* createProf_Campus(
                tenbool active);

tstProf_Extra* createProf_Extra(
                char* period);

tstCourse_Deg* createCourse_Deg(
                char* plan);


/*           PRIVATE FUNCTIONS           */
tstQueue* searchNodes(tstGraph *g, char *s);

void printGraph(tstGraph *g);
tenbool compString(char *str1, char *str2, uint8 n);
void printAdjElemQueue(tstQueue *q);
void decodeAndPrintNode(tstAdjElem* tmp);
/*******          MAIN              ********/
void main(void){

    tstGraph* g;
    tstQueue *q_AdjElem;

    g=createGraph();

    addStudent(g,"Jordan Abel","Avalos","Bueno","A01227033",Active);
    addStudent(g,"Fabian","Galindo","Sanchez","A01226208",Active);
    addStudent(g,"Jorge Ernesto","Castaneda","Hernandez","A01225503",Active);
    addStudent(g,"Jose Angel","Contreras","Godoy","A01226407",Active);
    addStudent(g,"Miguel","Hernandez","Hernandez","A01225503",Active);

    addProfessor(g,"Martin","Sinsel","Gonzalez","L01227584");
    addProfessor(g,"Luz Maria","Gomez","Hernandez","L01224744");
    addProfessor(g,"Jose Luis","Ponce","Davalos","L01229086");

    addCourse(g,"TC1207","Matematicas IV");
    addCourse(g,"TC1208","Microcontroladores");
    addCourse(g,"TC1209","Ecuaciones Dif");

    addDegree(g,"Ingenieria en Tecnologias Electronicas","ITE");
    addDegree(g,"Ingenieria en Biomedicina","IMD");
    addDegree(g,"Licenciatura en Derecho","LED");

    addArea(g,"EIAS");
    addArea(g,"ENH");

    addCampus(g,"Campus GDA","Guadalajara");
    addCampus(g,"Campus CEM","Estado de Mexico");

    addExtra(g,"Guitarra 1");
    addExtra(g,"Futbol");


    q_AdjElem = searchNodes(g,"Hernandez");
    printAdjElemQueue(q_AdjElem);
    DeleteQueue(q_AdjElem);

    addEdge(g,"Jordan","Matematicas IV");

    printGraph(g);
}


void printAdjElemQueue(tstQueue *q){
    
    tstAdjElem* node;

    while(Peek(q) != NULL_PTR){

        node=(tstAdjElem*) Dequeue(q);
        decodeAndPrintNode(node);
    }
}

void decodeAndPrintNode(tstAdjElem* tmp){
    switch(getNodeType(tmp)){

            case student:
                printf("Name of student is: %s %s %s\n", getStudentVertex(tmp)->name, getStudentVertex(tmp)->PLastName,getStudentVertex(tmp)->MLastName);
                printf("ID of student is: %s\n\n", getStudentVertex(tmp)->ID );
                break;

            case professor:
                printf("Name of professor is: %s %s %s\n", getProfessorVertex(tmp)->name, getProfessorVertex(tmp)->PLastName, getProfessorVertex(tmp)->MLastName);
                printf("ID of professor is: %s\n\n", getProfessorVertex(tmp)->ID );
                break;

            case course:
                printf("Name of course is:%s\n",getCourseVertex(tmp)->name);
                printf("Course ID is:%s\n\n",getCourseVertex(tmp)->CourseID);
                break;
            case degree:
                printf("Name of the degree is:%s\n",getDegreeVertex(tmp)->name);
                printf("Acronym of the degree is:%s\n\n",getDegreeVertex(tmp)->acronym);
                break;
            case area:
                printf("Name of the area is:%s\n\n",getAreaVertex(tmp)->name);
                break;
            case campus:

                printf("Name of the campus is:%s\n",getCampusVertex(tmp)->name);
                printf("Campus location is: %s\n\n",getCampusVertex(tmp)->location);
                break;
            case extra:
                printf("Name of the extra course is: %s\n\n",getExtraVertex(tmp)->name);
                break;
            default:
                break;
        }


}

void printGraph(tstGraph *g){


    tstAdjElem *tmp= g->adjListHead;
    
    printf("############################################\n");
    printf("Number of V::%i\n",g->V);
    printf("Number of E::%i\n",g->E);

    while(tmp != NULL_PTR){
        decodeAndPrintNode(tmp);
        tmp=tmp->next;
    }
    printf("############################################\n");;
}

tenbool compString(char *str1, char *str2, uint8 n){

    uint8 i;
    char tmp;
    for(i=0;i<n;){
        
        if(str1[i]>='A' && str1[i]<='Z' || str1[i]>='a' && str1[i]<='z'){
            if(str2[i]>='A' && str2[i]<='Z' || str2[i]>='a' && str2[i]<='z'){
                
                if(str2[i]<str1[i])     tmp = str1[i] - str2[i];
                else                    tmp = str2[i] - str1[i];
                
                if(tmp == 0 || tmp == 0x20 || tmp == 0xE0) i++;
                else return FALSE;

            }else{
                return FALSE;
            }
        }else{
            tmp = str2[i]-str1[i];
            if( tmp == 0 ) i++;
            else return FALSE;
        }
    }
    return TRUE;
}

tstQueue* searchNodes(tstGraph *g, char *s){
    
    tstQueue *q;
    tstAdjElem *tmp=g->adjListHead;
    
    q=CreateQueue();

    while(tmp != NULL_PTR){
        switch(getNodeType(tmp)){

            case student:
                if(compString(s,getStudentVertex(tmp)->name,strlen(s))==TRUE
                || compString(s,getStudentVertex(tmp)->PLastName,strlen(s))==TRUE
                || compString(s,getStudentVertex(tmp)->MLastName,strlen(s))==TRUE
                || compString(s,getStudentVertex(tmp)->ID,strlen(s))==TRUE)
                {
                    Enqueue(q,(void*)tmp);
                }
                break;
            case professor:
                if(compString(s,getProfessorVertex(tmp)->name,strlen(s))==TRUE
                || compString(s,getProfessorVertex(tmp)->PLastName,strlen(s))==TRUE
                || compString(s,getProfessorVertex(tmp)->MLastName,strlen(s))==TRUE
                || compString(s,getProfessorVertex(tmp)->ID,strlen(s))==TRUE){
                        Enqueue(q,(void*)tmp);
                }
                break;
            case course:
                if(compString(s,getCourseVertex(tmp)->name,strlen(s))==TRUE
                || compString(s,getCourseVertex(tmp)->CourseID,strlen(s))==TRUE)
                {
                    Enqueue(q,(void*)tmp);
                }

                break;
            case degree:
                if(compString(s,getDegreeVertex(tmp)->name,strlen(s))==TRUE
                || compString(s,getDegreeVertex(tmp)->acronym,strlen(s))==TRUE)
                {
                    Enqueue(q,(void*)tmp);
                }
                break;
            case area:
                if(compString(s,getAreaVertex(tmp)->name,strlen(s))==TRUE)
                {
                    Enqueue(q,(void*)tmp);
                }
                break;
            case campus:
                if(compString(s,getCampusVertex(tmp)->name,strlen(s))==TRUE
                || compString(s,getCampusVertex(tmp)->location,strlen(s))==TRUE)
                {
                    Enqueue(q,(void*)tmp);
                }
                 break;
            case extra:
                if(compString(s,getExtraVertex(tmp)->name,strlen(s))==TRUE)
                {
                    Enqueue(q,(void*)tmp);
                }
                 break;
            default:
                 break;
        }
        tmp = tmp->next;
    }
    return q;
}

void* safeMalloc(size){

    void* tmp = malloc(size);
    if(tmp == NULL_PTR) exit(0);

    return tmp;
}

/*************VERTEX FUNCTION************************/
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
    tmp->NodeType=extra;

    strncpy(str,name,strlen(name)+1);
    tmp->name=str;

    //add vertex to graph

    addVertex(g, (void*) tmp);

}

/*******************EDGES FUNCTIONS****************************/

tenbool addEdge(tstGraph *g, char *src, char *dst){
    tstQueue *q_src,*q_dst;
    tstAdjElem *n_src,*n_dst;
    tenbool boo=FALSE;
    tenEdgeType edgeType;
    tstAdjNode *src_curr,*new;
    void *new_info;

    q_src = searchNodes(g,src);
    q_dst = searchNodes(g,dst);
    if(q_src->size == 1){
        if(q_dst->size == 1){
            printf("Relation can be made!!\n");
            n_src=(tstAdjElem*) Dequeue(q_src);
            n_dst=(tstAdjElem*) Dequeue(q_dst);
            boo=TRUE;
        }else if(q_dst->size>1){
            printf("Multiple references in dst. Choose only one of these:\n");
            printAdjElemQueue(q_dst);
            return boo;
        }else{
            printf("Zero references in dst. Search again");
            return boo;
        }
        
    }else if(q_src->size>1){
        printf("Multiple references in src. Choose only one of these:\n");
        printAdjElemQueue(q_src);
        return boo;
    }else{
        printf("Zero references in src. Search again");
        return boo;
    }

    switch(getNodeType(n_src)){
        
        case student:
            switch(getNodeType(n_dst)){
                case course:
                    new_info= (void*)createStu_Cour(c_Approved,100,1);
                    edgeType=courses;
                    break;
                case degree:
                    new_info= (void*)createStu_Deg(1,9,active);
                    edgeType=isPartTo;
                    break;
                 case campus:
                    new_info= (void*)createStu_Camp(TRUE);
                    edgeType=studiesIn;
                    break;
                case extra:
                    new_info= (void*)createStu_Extra(e_Approved,1);
                    edgeType=coursesE;
                    break;
                default:
                    break;
            }
            break;
        
        case professor:
            switch(getNodeType(n_dst)){
                case course:
                    edgeType=teaches;
                    new_info= (void*)createProf_Course("XXXXX");
                    break;
                 case campus:
                    new_info= (void*)createProf_Campus(TRUE);
                    edgeType=teachesIn;
                    break;
                case extra:
                    new_info= (void*)createProf_Extra("XXXXX");
                    edgeType=teachesE;
                    break;
                default:
                    break;
            }
            break;
        
        case course:
            switch(getNodeType(n_dst)){
                case degree:
                    new_info=createCourse_Deg("ITE11");
                    edgeType=partOfPlan;
                    break;
                default:
                    break;
            }
            break;
        
        case degree:
            switch(getNodeType(n_dst)){
                case area:
                    new_info=NULL_PTR;
                    edgeType=belongsTo;
                    break;
                default:
                    break;
            }
            break;

        default:
            break;
    }

    src_curr=n_src->first_adj;
    if(src_curr !=NULL_PTR){
        while(src_curr->next != NULL_PTR) src_curr=src_curr->next;
    }

    new=(tstAdjNode*) safeMalloc(sizeof(tstAdjNode));
    new->EdgeType=edgeType;
    new->next=NULL_PTR;
    new->vertex= n_dst->vertex;
    new->info=new_info;

    if(src_curr==NULL_PTR) src_curr=new;
    else src_curr->next=new;
    g->E++;   
    
    DeleteQueue(q_src);
    DeleteQueue(q_dst);
    return boo;
    
}

tstStu_Cour* createStu_Cour( tenCourseState state,
                uint8 grade,
                uint8 semester)
{
    tstStu_Cour *tmp;

    tmp= (tstStu_Cour*) safeMalloc(sizeof(tstStu_Cour));
    tmp->state=state;
    tmp->grade=grade;
    tmp->semester=semester;

    return tmp;
}

tstStu_Deg* createStu_Deg(
                uint8 initSemester,
                uint8 finalSemester,
                tenStu_DegStatus state)
{
    tstStu_Deg* tmp;
    tmp = (tstStu_Deg*) safeMalloc(sizeof(tstStu_Deg));
    tmp->initSemester=initSemester;
    tmp->finalSemester=finalSemester;
    tmp->state=state;

    return tmp;
}

tstStu_Camp* createStu_Camp(
                tenbool native)
{
    tstStu_Camp* tmp;
    tmp = (tstStu_Camp*) safeMalloc(sizeof(tstStu_Camp));
    tmp->Native=native;

    return tmp;
}

tstStu_Extra* createStu_Extra(
                tenExtraState state,
                uint8 semester)
{
    tstStu_Extra* tmp;
    tmp = (tstStu_Extra*) safeMalloc(sizeof(tstStu_Extra));
    tmp->semester=semester;
    tmp->state=state;

    return tmp;
}

tstProf_Course* createProf_Course(
                char* period)
{
    tstProf_Course* tmp;
    tmp = (tstProf_Course*) safeMalloc(sizeof(tstProf_Course));
    strncpy(tmp->period,period,strlen(period));

    return tmp;
}

tstProf_Campus* createProf_Campus(
                tenbool active)
{
    tstProf_Campus* tmp;
    tmp = (tstProf_Campus*) safeMalloc(sizeof(tstProf_Campus));
    tmp->active=active;

    return tmp;
}

tstProf_Extra* createProf_Extra(
                char* period)
{
    tstProf_Extra* tmp;
    tmp = (tstProf_Extra*) safeMalloc(sizeof(tstProf_Extra));
    strncpy(tmp->period,period,strlen(period));

    return tmp;
}

tstCourse_Deg* createCourse_Deg(
                char* plan)
{
    tstCourse_Deg* tmp;
    tmp = (tstCourse_Deg*) safeMalloc(sizeof(tstCourse_Deg));
    strncpy(tmp->plan,plan,strlen(plan));

    return tmp;
}



//Graph constructor
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
