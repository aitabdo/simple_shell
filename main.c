#include "shell.h"

/* @aitabdo..... */
/**
 * main - entry point.
 * @ac: argument pointer.
 * @av: argument pointer.
 * @env: argument pointer.
 * Return: int (return_status).
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL, **commands = NULL;
	size_t len = 0;
	ssize_t x;
	int return_status = 0;

	(void)ac;

	while (true)
	{
		if (isatty(0))
			write(1, "$ ", 2);

		x = getline(&line, &len, stdin);
		if (x == -1)
		{
			free(line);
			line  = NULL;
			if (isatty(0))
				write(1, "\n", 1);
			return (return_status);
		}

		commands  = process_line(line);
		if (!commands)
		{
			free(line);
			line = NULL;
			continue;
		}

		(return_status) = execute_line(commands, av, env);
	}
}

