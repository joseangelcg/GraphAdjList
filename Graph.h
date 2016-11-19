#ifndef _GRAPH_H
#define _GRAPH_H

/*********INCLUDES***********/

#include "types.h"
/*********DEFINES**********/

#define DT_VERTEX   uint16
#define MAX_VERTEX  65535
#define NULL_PTR    NULL

/***********MACROS***********/

/**********TYPEDEFS**************/

typedef enum relation{
   
    courses=0, //Student-course
    isPartTo,  //Student-degree
    studiesIn, //Student-campus
    coursesE,  //Student-extra
    teaches,   //profesor-course
    partOfPlan,//course-degree
    teachesIn, //professor-campus
    teachesE,  //professor-extra
    belongsTo  //degree-Area
        
}tenEdgeType;

typedef struct node{
    
    tenEdgeType EdgeType;
    struct node* next;
    void* vertex; //pointer to adjacent element
    
    //char* info;

}tstAdjNode;

typedef enum nodeType{

    student=0,
    course,
    professor,
    degree,
    area,
    campus,
    extra

}tenNodeType; 

typedef enum StudentStatus{

    Inactive=0,
    Active

}tenStuStatus;

typedef struct v_student{
    
    tenNodeType NodeType;
    
    char* name;
    char* PLastName;
    char* MLastName;
    char* ID;
    tenStuStatus Status;

}tstStudentV;

typedef struct v_course{

    tenNodeType NodeType;

    char* CourseID;
    char* name;
    
}tstCourseV;

typedef struct v_professor{

    tenNodeType NodeType;

    char* name;
    char* PLastName;
    char* MLastName;
    char* ID;
    
}tstProfessorV;

typedef struct v_degree{

    tenNodeType NodeType;

    char* name;
    char* acronym;
    
}tstDegreeV;

typedef struct v_area{

    tenNodeType NodeType;

    char* name;

}tstAreaV;

typedef struct v_campus{

    tenNodeType NodeType;

    char* name;
    char* location;

}tstCampusV;

typedef struct v_extra{
    
    tenNodeType NodeType;

    char* name;

}tstExtraV;

typedef struct adjElement{

    void *vertex;
    struct adjElement *next;
    tstAdjNode *first_adj;

}tstAdjElem;

typedef struct graph{
    
    uint16 V;
    uint16 E;

    tstAdjElem *adjListHead;
    tstAdjElem *adjListTail;
    
}tstGraph;

/*******FUNCTION PROTOTYPES************/

tstGraph* createGraph(void);
tenbool addEdge(tstGraph* g,uint16 src, uint16 dst);

#endif //_GRAPH_H
