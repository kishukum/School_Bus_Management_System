#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "main.h"
void freeBusrouteLinkedList(busroute** br)
{
    busroute* iter   = *br;
    int recordsFreed = 0;
    while ( iter != NULL )
    {
        busroute* temp = iter ;
        iter = iter -> next ;
        if ( temp != NULL)
        {
            free (temp);
            recordsFreed++;
        }
    }
    return recordsFreed;

}
void appendBusroute(busroute **headPointer, busroute* data)
{
    if ( headPointer == NULL )
        EXIT_FAILURE;

    busroute* iter = *headPointer ;

    if ( *headPointer == NULL ) 
    {
        *headPointer = data ;
    }
    else
    {
        while ( iter -> next != NULL)
            iter = iter -> next;
        iter -> next = data ;
    }
    data -> next = NULL ;
    return EXIT_SUCCESS ;
}
int  insertAfter(int brId , busroute** headP, busroute* newbr, busroute **tailP)
{
    int insert = 0;

    if ( headP == NULL || newbr== NULL)
        return OPERATION_FAIL ;

    if (*headP == NULL ) 
    {
        appendBusroute(headP, newbr);
        return EXIT_SUCCESS ;
    }

    busroute* iter = *headP;

    while ( iter != NULL)  
    {
        if ( iter -> studentID == brId )
        {
            busroute *temp = iter -> next;
            iter -> next = newbr ;
            newbr -> next = temp ;
            insert =  1;
            break;
        }
        iter = iter -> next;
    }
    if (insert == 1)
        return OPERATION_SUCCESS;
    else
        return BUSROUTE_NOTFOUND ;

}
int loadFromFileBusroute(const char *fileName, busroute **headPointer)
{
    char lineBuffer[ST_LINE_BUFFER];
    const char* seperator = "|" ;
    char* token    = NULL ;
    busroute *iter = NULL;
    int lineCount  = 0;

    FILE* brFile = fopen (fileName, "r");
    if (brFile == NULL )
    {
        printf("INVALID!!! %s\n", fileName);
        return FAILURE ;
    }

    while ( fgets ( lineBuffer, ST_LINE_BUFFER, brFile) != 0)
    {
        iter = (busroute*) malloc (sizeof(busroute));
        if ( iter == NULL )
        {
            printf("DROP!!!n");
            break;
        }
        token = strtok (lineBuffer, seperator);

        if ( token != NULL)
        {
         iter -> studentID = atoi(token);
        }
        token = strtok (NULL, seperator);
        if ( token != NULL)
        {
         iter -> stopID = atoi(token);
        }
        token = strtok (NULL, seperator);
         if ( token != NULL)
        {
            iter -> amount = atoi(token);
        }
        token = strtok (NULL, seperator);
         if ( token != NULL)
        {
            iter -> status = atoi(token);
        }
        iter -> next = NULL ;

        appendBusroute ( headPointer, iter );
        lineCount++;
    }
    fclose(brFile);
    return lineCount;
}
busroute* searchBusroute (busroute* headPointer, int brId)
{
    if (headPointer == NULL || brId <= 0) 
        return NULL ;

    busroute *iter = headPointer ;
    while ( iter != NULL )
    {
        if ( iter-> studentID == brId )
        {
            return iter;
        }
        iter = iter -> next ;
    }
    return NULL ;
}
busroute* searchBusrouteName (busroute* headPointer, const char* stfirstName)
{
    if (headPointer == NULL ||stfirstName == 0 || strlen(stfirstName) == 0)
        return NULL ;

    busroute *returnList = NULL ;

    busroute *iter = headPointer ;
    while ( iter != NULL )
    {
        if ( strcmp (iter-> stopName ,  stfirstName ) == 0)
        {
            busroute* temp = (busroute*)malloc(sizeof(busroute));
            *temp = *iter ;
            appendBusroute(&returnList, temp);
        }
        iter = iter -> next ;
    }
    return returnList ;
}



