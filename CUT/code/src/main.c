#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "main.h"
#include <unistd.h>
#include <string.h>

int removeStudent(student** st, int stId)
{
    char buff[4096];
    char temp[4096];
    char lineBuffer[ST_LINE_BUFFER];
    const char* seperator = "|" ;
    char cpy[ST_LINE_BUFFER];
    char *token;

    FILE* stFile = fopen ("../data/student.csv", "r");
    
    while ( fgets ( lineBuffer, ST_LINE_BUFFER, stFile) != 0)
    {
	    strcpy(cpy, lineBuffer);
	    token = strtok (lineBuffer, seperator);
	    if (atoi(token) == stId)
	    {
		    printf("droping\n");
		    continue;
	    }
	    else
	    {
	      strcpy(temp, buff);
	      sprintf(buff, "%s%s",temp, cpy );

	    }
      
    }
    fclose(stFile);
    stFile = fopen ("../data/student.csv", "w");
    fwrite(buff, 1, strlen(buff), stFile);
    fclose(stFile);

    return EXIT_SUCCESS;
}

void doRemoveStudent(student** st)
{
    int stId = 0;
    printf("Enter Student Id\n");
    if ( 1 != scanf("%d", &stId))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }

    int retValue =  removeStudent(st,stId);
    if ( retValue == EXIT_SUCCESS)
        printf("Student with Id %d DROP\n", stId);
    else
        printf("INVALID!\n");
}
void doDisplayStudent(student**st)
{
}
void doChangeStudentDepartment(student** st)
{
    int stId = 0;
    printf("Enter Student Id\n");
    if ( 1 != scanf("%d", &stId))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }
    printf("To be implemented\n");
}

void doAddStudent(student**st)
{
    int stId = 0;
    int amount = 0;
    char firstName[FNAME_LEN] ;
    char lastName[LNAME_LEN] ;
    char username[FNAME_LEN] ;
    char password[FNAME_LEN] ;
    char buff[1024];
    printf("Enter Student Id\n");
    if ( 1 != scanf("%d", &stId))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }

    printf("Enter first name \n");
    if ( scanf("%s", firstName) != 1 )
    {
        fflush(stdin);
        printf("Please enter a valid name\n");
        return ;
    }

    printf("Enter last name \n");
    if ( scanf("%s", lastName) != 1 )
    {
        fflush(stdin);
        printf("Please enter a valid name\n");
        return ;
    }

    printf("Enter user name \n");
    if ( scanf("%s", username) != 1 )
    {
        fflush(stdin);
        printf("Please enter a valid name\n");
        return ;
    }
    printf("Enter password name \n");
    if ( scanf("%s", password) != 1 )
    {
        fflush(stdin);
        printf("Please enter a valid name\n");
        return ;
    }
    printf("Enter Student amount\n");
    if ( 1 != scanf("%d", &amount))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }
    
    student *newSt = (student*)malloc(sizeof(student));
    strcpy(newSt -> firstName, firstName);
    strcpy(newSt -> lastName, lastName);
    strcpy(newSt -> userName, username);
    strcpy(newSt -> password, password);
    
    newSt -> studentID = stId ;
    newSt -> amount = amount ;
    newSt -> status = 'Q' ;


    appendStudent(st, newSt);
    sprintf(buff, "%d|%s|%s|%s|%s|%d|%c\n", newSt -> studentID, newSt -> firstName, newSt -> lastName, newSt -> userName, newSt -> password, newSt -> amount, newSt -> status);
    FILE *st_file = NULL;
    st_file = fopen("../data/student.csv", "a+");
    fseek(st_file, 0, SEEK_END);
    fwrite(buff, 1, strlen(buff), st_file);
    fclose(st_file);

}
void display_busstops()
{
  char lineBuffer[ST_LINE_BUFFER];
  const char* seperator = "|" ;
  char* token = NULL ;
  FILE* stFile = fopen ("../data/busroute.csv", "r");
  while ( fgets ( lineBuffer, ST_LINE_BUFFER, stFile) != 0)
  {
    token = strtok (lineBuffer, seperator);
    token = strtok (NULL, seperator);
    token = strtok (NULL, seperator);
    printf("%s\n", token);
  }
  printf("\n");
  fclose(stFile);
}
void add_busstop()
{
    int stId;
    int stopId;
    char stopName[256];
    int distance;
    int amount;
    char status = 'N';
    char buff[1024];

    printf("Enter Student Id\n");
    if ( 1 != scanf("%d", &stId))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }

    printf("Enter Stop Id\n");
    if ( 1 != scanf("%d", &stopId))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }

    printf("Enter stop name \n");
    if ( scanf("%s", stopName) != 1 )
    {
        fflush(stdin);
        printf("Please enter a valid name\n");
        return ;
    }

    printf("Enter Distance\n");
    if ( 1 != scanf("%d", &distance))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }

    printf("Enter Amount\n");
    if ( 1 != scanf("%d", &amount))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }
    sprintf(buff, "%d|%d|%s|%d|%d|%c\n", stId, stopId, stopName, distance, amount, status);
    FILE *br_file = fopen("../data/busroute.csv", "a+");
    fseek(br_file, 0, SEEK_END);
    fwrite(buff, 1, strlen(buff), br_file);
    fclose(br_file);

}
void doDisplayAddbusStop(student** st)
{
	int ch;
	printf("\npress 1 to see all available bus stops\n");
	printf("press 2 to add bus stops\n");
        scanf("%d", &ch);
	if(ch == 1)
	{
	  display_busstops();
	}
	else if(ch == 2)
	{
	  add_busstop();
	}
	else
	{
	  printf("\nPlease enter valid choice\n");
	}

}
void  menu(student** st)
{
    int ch ;
    int returnValue = 0;
    
    do 
    {
        printf("Welcome to School Bus Management system\n");    
        printf("1. Add new Student\n");
        printf("2. Remove an Student \n");
        printf("3. Add busStop\n");
        printf("4. bus amount\n");
        printf("5. Exit \n");
        printf("\nEnter Your Choice : ");


        returnValue = scanf ("%d", &ch);
        if ( returnValue == 0 || returnValue ==  EOF)
        {
            fflush(stdin);
            printf("Invalid input. Please enter valid input\n");
            continue ; 
        }

        switch(ch)
        {
            case 1:
                doAddStudent(st);
                break;
            case 2:
                doRemoveStudent(st);
                break;
            case 3:
                doDisplayAddbusStop(st);
                break;
            case 4:
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid operation\n");
                break;
        }

    } while ( ch != 5);

}

int main(int argc, char** argv)
{
    student* st[MAXST];
    student* stp;
    busroute* bus_route[MAXST];
    busroute* brp;
    for(int i =0; i < MAXST; i++)
        st[i] = NULL ;

    loadFromFile_st("../data/student.csv", &st[0]);
    stp = st[0];
    brp = bus_route[0];
    
    menu(st);

    return EXIT_SUCCESS;
} 







