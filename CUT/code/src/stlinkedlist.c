#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "main.h"
int freeStudentLinkedList(student** st)
{
    student* iter   = *st;
    int recordsFreed = 0;
    while ( iter != NULL )
    {
        student* temp = iter ;
        iter = iter -> next ;
        if ( temp != NULL)
        {
            free (temp);
            recordsFreed++;
        }
    }
    return recordsFreed;

}
int appendStudent(student **headPointer, student* data)
{
    if ( headPointer == NULL )
        EXIT_FAILURE;

    student* iter = *headPointer ;

    if ( *headPointer == NULL ) 
        *headPointer = data ;
    else
    {
        while ( iter -> next != NULL)
            iter = iter -> next;
        iter -> next = data ;
    }
    data -> next = NULL ;
    return EXIT_SUCCESS ;
}
int loadFromFilestudent(const char *fileName, student **headPointer)
{
    char lineBuffer[ST_LINE_BUFFER];
    const char* seperator = "|" ;
    char* token    = NULL ;
    student *iter = NULL;
    int lineCount  = 0;

    FILE* stFile = fopen (fileName, "r");
    if (stFile == NULL )
    {
        printf("INVALID!!! %s\n", fileName);
        return FAILURE ;
    }
    token = strtok (lineBuffer, seperator);
    while ( fgets ( lineBuffer, ST_LINE_BUFFER, stFile) != 0)
    {
        iter = (student*) malloc (sizeof(student));
        if ( iter == NULL )
        {
            printf("DROP!!!n");
            break;
        }

        token = strtok (NULL, seperator);
        if ( token != NULL)
        {
         iter -> studentID = atoi(token);
        }
        
        token = strtok (NULL, seperator);
        if ( token != NULL)
        {
            strncpy(iter -> firstName, token, FNAME_LEN - 1);
        }
        
        token = strtok (NULL, seperator);
        if ( token != NULL)
        {
            strncpy(iter -> lastName, token, LNAME_LEN - 1);
        }
        
        token = strtok (NULL, seperator);
          if ( token != NULL)
        {
            strncpy(iter -> userName, token, USERNAME_LEN - 1);
        }

        token = strtok (NULL, seperator);
          if ( token != NULL)
        {
            strncpy(iter -> password, token, PASSWORD_LEN - 1);
        }

        token = strtok (NULL, seperator);
        if ( token != NULL)
        {
            iter -> amount = atoi(token);
        }

         token = strtok (NULL, seperator);
         if ( token != NULL)
        {
            iter -> status = token;
        }
    
        iter -> next = NULL ;

        appendStudent ( headPointer, iter );
        lineCount++;
    }

    fclose(stFile);
    return lineCount;
}
student* searchStudentId (student* headPointer, int stId)
{
    if (headPointer == NULL || stId <= 0) 
        return NULL ;

    student *iter = headPointer ;
    while ( iter != NULL )
    {
        if ( iter-> studentID == stId )
        {
            return iter;
        }
        iter = iter -> next ;
    }
    return NULL ;
}
student* searchStudentName (student* headPointer, const char* stfirstName)
{
    if (headPointer == NULL ||stfirstName == 0 || strlen(stfirstName) == 0)
        return NULL ;

    student *returnList = NULL ;

    student *iter = headPointer ;
    while ( iter != NULL )
    {
        if ( strcmp (iter-> firstName ,  stfirstName ) == 0)
        {
            student* temp = (student*)malloc(sizeof(student));
            *temp = *iter ;
            appendStudent(&returnList, temp);
        
        }
        iter = iter -> next ;
    }
    return returnList ;
}



