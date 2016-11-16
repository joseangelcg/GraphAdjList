#ifndef _TYPES_H
#define _TYPES_H

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int    uint32;
typedef unsigned long   uint64;

typedef signed char     int8;
typedef signed short    int16;
typedef signed int      int32;
typedef signed long     int64;

typedef enum enbool{
    FALSE=0,
    TRUE    
}tenbool;

typedef void (*pvFunc)(void);// void/void function pointer

/*
   If you want another function pointer, define it yourself xD
 */

#endif //_TYPES_H
