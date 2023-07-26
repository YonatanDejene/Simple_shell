#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80
#define PROMPT "osh>"

int main(void)
{
	char *args[MAX_LINE/2 + 1];
	int should_run = 1;
	char cmd[MAX_LINE];
	
	while (should_run)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		
		if (fgets(cmd, MAX_LINE, stdin) == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		
		cmd[strcspn(cmd, "\n")] = '\0';
		args[0] = cmd;
		rgs[1] = NULL;
		pid_t pid = fork();
		
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				char error_msg[] = ": command not found\n";
				write(STDERR_FILENO, args[0], strlen(args[0]));
				write(STDERR_FILENO, error_msg, strlen(error_msg));
				exit(1);
			}
		}
		
		else
		{
			wait(NULL);
		}
	}
	
	return 0;
}
