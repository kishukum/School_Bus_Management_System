#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#include "main.h"
void display_Student(student* st)
{
    printf("|%d |%-10s |%-12s |%10s |%3s |%12d |%6c\n",
        st->studentID,
        st->firstName,
        st->lastName,
        st->userName,
		st->password,
		st->amount,
        st->status);
}
void printStudentLinkedList(student *st)
{
    student* iter = st;
    while ( iter != NULL )
    {
        display_Student(iter);
        iter = iter -> next ;
    }
}

int loadFromFile_st(const char *fileName, student **headPointer)
{
        char lineBuffer[ST_LINE_BUFFER];
        const char* seperator = "|" ;
        char* token = NULL ;
        student *iter = NULL;

        FILE* stFile = fopen (fileName, "r");
        if (stFile == NULL )
    {
                printf("INVALID!!! %s\n", fileName);
                return EXIT_FAILURE ;
        }

        while ( fgets ( lineBuffer, ST_LINE_BUFFER, stFile) != 0)
        {
                iter = (student*) malloc (sizeof(student));
                if ( iter == NULL )
                {
                        printf("DROP!!!\n");
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
                        iter -> status = atoi(token);
                }
                iter -> next = NULL ;
                appendStudent ( headPointer, iter );
        }
        fclose(stFile);
        return 0;
}


