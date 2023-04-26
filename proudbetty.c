#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0 on success, -1 on failure
 */
int main(void)
{
	char *line;
	size_t bufsize = 0;
	ssize_t chars_read;
	char *args[BUFSIZE];
	int i;

	while (1)
	{
		printf("$ ");
		chars_read = getline(&line, &bufsize, stdin);

		if (chars_read == -1)
			break;

		line[chars_read - 1] = '\0';

		args[0] = strtok(line, " ");
		for (i = 1; i < BUFSIZE; i++)
		{
			args[i] = strtok(NULL, " ");

			if (args[i] == NULL)
				break;
		}

		/* Do something with the args array */
	}

	free(line);

	return (0);
}
