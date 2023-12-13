#include "shell.h"
int main(void)
{
    extern char **environ;
    char *buffer = NULL;
    char **av = NULL;
    char *command = NULL;
    char *program_path;
    char *token;
    int status;
    int pexist;
    size_t len = 0;
    ssize_t a;
    pid_t pid;
    unsigned int i = 0;

    /* Check if the shell is in interactive mode */
    int interactive = isatty(STDIN_FILENO);

    char buffer_i[16]; /* Assuming the line number won't be longer than 16 digits */

    while (1)
    {
        if (interactive)
	  {
            /* Display shell prompt in interactive mode*/
            write(1, "cisfun$ ", 8);
            fflush(stdout);
        }

        a = getline(&buffer, &len, stdin);
        if (a == -1)
	  {
            if (interactive)
	      {
	      /* Handle EOF in interactive mode */
                write(STDOUT_FILENO, "\n", 1);
            }
            free(buffer);
	    return (0);
        }

        /* Trim newline character */
        if (buffer[a - 1] == '\n')
	  {
            buffer[a - 1] = '\0';
        }

        if (_strcmp(buffer, "") == 0)
	  {
                continue;  /* Ignore empty lines */
        }

        av = malloc(sizeof(char *) * 1024);
	if (av == NULL) /*add condition */
	  {
	    return (0);
	  }
        token = strtok(buffer, " \n");
	i = 0;
        while (token != NULL)
	  {
            av[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        av[i] = NULL;
        if (_strcmp(av[0], "exit") == 0)
	  {
            free(buffer);
            free(av);
	    return (0);
        }
        if (_strcmp(av[0], "env") == 0)
	  {
            _env();
        }
	else
	  {
            pexist = pathexist(av[0]);

            if (pexist == 1)
	      {
                program_path = getcwd(NULL, 0);
                /* anzidou hadi */
                if (program_path == NULL)
                {
                       perror("getcwd");
                       free(buffer);
                       free(av);
		       return (0);
                }/* salat hnaya */
                if (program_path != NULL)
                {
                    write(STDERR_FILENO, program_path, _strlen(program_path));
                    free(program_path);/* zedtha hnaya */
                    program_path = NULL;
                }
                write(STDERR_FILENO, ": ", 2);

                intToStr(i, buffer_i);
                write(STDERR_FILENO, buffer_i, _strlen(buffer_i));
                write(STDERR_FILENO, ": ", 2);
                write(STDERR_FILENO, av[0], _strlen(av[0]));
                write(STDERR_FILENO, ": No such file or directory\n", 28);
                free(program_path); /*an7etou hadi hnaya */
              }
            else
	      {
                pid = fork();

                if (pid == -1)
		  {
                    perror(av[0]);
                    free(av);
                    free(buffer);
		     return (1); /*changement de -1 à 1 */
                }

                if (pid == 0)
		  {
                    command = fullPath(av[0]);
                    if (execve(command, av, environ) == -1)
		      {
                        perror(av[0]);
                        free(command);
                        free(av); /*je teste ici free ya rebbi */
                        free(buffer);
			return (1);	/*change return value from 0 to 1*/
			exit(EXIT_FAILURE); /* petit test */
                    }
                }
		else
		  {
                    wait(&status);
                    free(command);
                }
            }
	  }
        free(av);/*Anjerbou hnaya */
     /* Do not free av here, as it may have been overwritten by execve */
    }
    free(buffer);
    free(av); /* nzidou we7da khra */
    return (0);
}
