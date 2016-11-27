#ifndef _GRAPH_H
#define _GRAPH_H

/*********INCLUDES***********/

#include "types.h"
/*********DEFINES**********/

#define DT_VERTEX   uint16
#define MAX_VERTEX  65535
#define NULL_PTR    NULL

/***********MACROS***********/
#define getNodeType(tmp)     *((tenNodeType* )(tmp->vertex))

#define getStudentVertex(tmp)       ((tstStudentV*)(tmp->vertex))
#define getCourseVertex(tmp)        ((tstCourseV*)(tmp->vertex))
#define getProfessorVertex(tmp)     ((tstProfessorV*)(tmp->vertex))
#define getDegreeVertex(tmp)        ((tstDegreeV*)(tmp->vertex))
#define getAreaVertex(tmp)          ((tstAreaV*)(tmp->vertex))
#define getCampusVertex(tmp)        ((tstCampusV*)(tmp->vertex))
#define getExtraVertex(tmp)         ((tstExtraV*)(tmp->vertex))


#define nInvalidGrade           (uint8)0xFF;

/**********TYPEDEFS**************/

/********EDGES DEFINITIONS**************/
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

//student-course
typedef enum course_state{
    c_inCourse=0,
    c_Approved,
    c_Failed
}tenCourseState;

typedef struct stu_cou{
    tenCourseState state;
    uint8 grade;
    uint8 semester;
}tstStu_Cour;

//student-degree
typedef enum stu_deg_state{
    inactive=0,
    active
}tenStu_DegStatus;

typedef struct stu_deg{
    uint8 initSemester;
    uint8 finalSemester;
    tenStu_DegStatus state;
}tstStu_Deg;

//student-campus
typedef struct stu_camp{
    tenbool Native;
}tstStu_Camp;

//student-extra
typedef enum extra_state{
    e_inCourse=0,
    e_Approved,
    e_Failed
}tenExtraState;

typedef struct stu_ext{
    tenExtraState state;
    uint8 semester;
}tstStu_Extra;

//Profesor-course
typedef struct prof_cou{
    char period[5];
}tstProf_Course;

//profesor-campuse
typedef struct prof_camp{
    tenbool active;
}tstProf_Campus;

//profesor-extra
typedef struct prof_ext{
    char period[5];
}tstProf_Extra;

//degree-area   
//No information stored in this relationship

//course-degree
typedef struct cour_deg{
    char plan[7];
}tstCourse_Deg;

/********VERTEX DEFINITIONS**************/
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
