#include "shell.h"
/* @aitabdo..... */
/**
 * free_commands - frees our commands 2d list.
 * @commands: our 2d list.
 * Return: nothing (void).
 */
void free_commands(char **commands)
{
	ssize_t k = 0, length = 0;

	if (!commands)
		return;
	while (commands[k])
	{
		length++;
		k++;
	}
	for (k = 0 ; k < length ; k++)
	{
		free(commands[k]);
		commands[k] = NULL;
	}
	free(commands);
	commands = NULL;
}

