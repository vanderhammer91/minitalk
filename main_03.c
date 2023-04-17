#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig)
{
	printf("/nHINT: Remember that multiplication is repetitive addition!\n");
}

int	main(void)
{
	int pid = fork();
	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		//child process
		sleep(6);
		//send signal to parent..
		kill(getppid(), SIGUSR1);

	}
	else
	{
		//parent process.
		//-------------------------------------
		struct sigaction sa = { 0 };
		//Because we are using scanf, we want scanf to restart after execution
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);

		int x;
		printf("What is the result of 3 x 5: ");
		scanf("%d", &x);
		if (x == 15)
			printf("That is . . correct :)\n");
		else
			printf("BUBOW! WRONG\n");
		wait(NULL);
	}

	return (0);
}
