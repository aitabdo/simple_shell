#ifndef SHELL_H
#define SHELL_H
/********* macros / global variables ****/

#define DELIMINATOR "\t\n "
#define true 1

/***************************************/

/*********** functions prototypes *********/

char **process_line(char *line);
void free_commands(char **commands);
int execute_line(char **commands, char **av, char **env);

/***************************************/
/************ libraries ***********/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/*****************************************/
#endif

