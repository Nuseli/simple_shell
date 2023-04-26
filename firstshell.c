#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	char *token;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		/* Read in user input */
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			/* End of file condition */
			break;
		}

		/* Remove newline character from input */
		command[strcspn(command, "\n")] = 0;

		/* Tokenize command line into arguments */
		int i = 0;
		token = strtok(command, " ");
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		/* Fork process */
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			/* Child process */

			/* Execute command */
			if (execvp(args[0], args) == -1)
			{
				/* If execvp returns -1, the command was not found */
				fprintf(stderr, "Command not found: %s\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */

			 /* Wait for child process to complete */
			int status;
			if (wait(&status) == -1)
			{
				perror("wait failed");
				exit(EXIT_FAILURE);
			}
		}
	}

	return (0);
}
