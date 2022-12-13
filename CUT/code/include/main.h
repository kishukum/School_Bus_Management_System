#ifdef __MAIN_H__
#define __MAIN_H__
#include <struct.h>

extern int loadFromFileStudent(const char* fileName, student **);
extern void display_Student(student* );
extern void printStudentLinkedList(student *);
extern void freeStudentLinkedList(student **);
extern int appendStudent(student **headPointer, student* data);

extern int loadFromFileBusroute(const char* fileName, busroute **);
extern void display_Busroute(busroute* );
extern void printBusrouteLinkedList(busroute *);
extern void freeBusrouteLinkedList(busroute **);
extern void appendBusroute(busroute **headPointer, busroute* data);

#endif



