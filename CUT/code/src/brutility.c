#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "main.h"
void display_Busroute(busroute* br)
{
    printf("|%d |%-10d |%-15s |%10d |%10d |%10c\n",
        br->studentID,
        br->stopID,
        br->stopName,
        br->busDistance,
		br->amount,
        br->status);
}
void printBusrouteLinkedList(busroute *br)
{
    busroute* iter = br;
    while ( iter != NULL )
    {
        display_Busroute(iter);
        iter = iter -> next ;
    }

}
int loadFromFile_br(const char *fileName, busroute **headPointer)
{
	char lineBuffer[ST_LINE_BUFFER];
	const char* seperator = "|" ;
	char* token = NULL ;
	busroute *iter = NULL;

	FILE* brFile = fopen (fileName, "r");
	if (brFile == NULL )
    {
		printf("INVALID!!! %s\n", fileName);
		return EXIT_FAILURE ;
	}	

	while ( fgets ( lineBuffer, ST_LINE_BUFFER, brFile) != 0)
	{
		iter = (busroute*) malloc (sizeof(busroute));
		if ( iter == NULL )
		{
			printf("DROP!!!\n");
			break;
		}
		token = strtok (lineBuffer, seperator);

		if ( token != NULL)
		{
			iter -> studentID = atoi(token);
			printf("\n std_id = %d\n", iter -> studentID);
		}
		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> stopID = atoi(token);
			printf("stopID = %d\n", iter -> stopID);
		}
		token = strtok (NULL, seperator);
        
        if ( token != NULL)
		{
			strncpy(iter -> stopName, token, STOPNAME_LEN - 1);
			printf("stop_name = %s\n", iter -> stopName);
		}
		token = strtok (NULL, seperator);
        if ( token != NULL)
		{
			iter -> busDistance = atoi(token);
			printf("busdistance = %d\n", iter -> busDistance);
		}
		token = strtok (NULL, seperator);
        
		if ( token != NULL)
		{
			iter -> amount = atoi(token);
			printf("amount = %d\n", iter -> amount);
		}
        token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			iter -> status = atoi(token);
			printf("status = %c\n", iter -> status );
		}
		iter -> next = NULL ;
		printf("br\n");
		appendBusroute ( headPointer, iter );
	}
	fclose(brFile);
	return 0;
}
 


