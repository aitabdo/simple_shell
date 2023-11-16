#include "shell.h"

/* @aitabdo..... */
/**
 * process_line - processing our line.
 * @s: our line (type:string characters).
 * Return: char (our 2d array after line being processed).
 */

char **process_line(char *s)
{
	char *sub_line = NULL, *temp_str = NULL, **commands = NULL;
	ssize_t length = 0, j = 0;

	temp_str = strdup(s);

	sub_line = strtok(temp_str, DELIMINATOR);

	/* if user entered " "or "\n" or "\t"*/
	if (sub_line == NULL)
	{
		free(temp_str);
		temp_str = NULL;
		return (NULL);
	}
	/* indicating number of sub_lines in *s(line) and the length of **commands*/
	for (j = 0 ; sub_line ; j++)
	{
		length++;
		sub_line = strtok(NULL, DELIMINATOR);
	}
	free(temp_str);
	temp_str = NULL;

	/* allocating memory for **commands(our 2D array) */
	commands = malloc(sizeof(char *) * (length + 1));
	if (!commands)
	{
		return (NULL);
	}
	/* filling out the **commands(our 2D array) with sub_lines */
	sub_line = strtok(s, DELIMINATOR);
	for (j = 0 ; j < length ; j++)
	{
		commands[j] = strdup(sub_line);
		sub_line = strtok(NULL, DELIMINATOR);
	}
	commands[length] = NULL;
	return (commands);

}

