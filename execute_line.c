#include "shell.h"

/* @aitabdo..... */
/**
 * execute_line - exicuting our line(commands).
 * @commands: argument pointer to 2d list.
 * @av: argv.
 * @env: variable envirement.
 * Return: int (return_status).
 */
int execute_line(char **commands, char **av, char **env)
{
	pid_t child_pid;
	int return_status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(commands[0], commands, env) == -1)
		{
			perror(av[0]);
			free_commands(commands);
			exit(127);
		}
	}
	else
	{
		wait(&return_status);
		free_commands(commands);
	}

	return (__WEXITSTATUS(return_status));
}

