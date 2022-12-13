#ifndef _STRUCT_H_
#define _STRUCT_H_

#define FNAME_LEN 40
#define LNAME_LEN 40
#define USERNAME_LEN 20
#define PASSWORD_LEN 20
#define STOPNAME_LEN 30
#define ST_LINE_BUFFER 256
#define BUSROUTE_LINE_BUFFER 256
#define STUDENT_NOTFOUND -1
#define BUSROUTE_NOTFOUND -1
#define OPERATION_FAIL -2
#define OPERATION_SUCCESS 0 
#define MAXEMP 20
#define MAXST 10
#define FAILURE -1

typedef struct _student_
{
    int studentID ;
    char firstName[FNAME_LEN];
    char lastName[LNAME_LEN];
    char userName[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int  amount;
    char status;

    struct _student_ *next;
} student;

typedef struct _busroute_
{
    int studentID ;
    int stopID;
    char stopName[STOPNAME_LEN];
    int  busDistance;
    int  amount;
    char status;
    struct _busroute_ *next;
} busroute;
#endif



