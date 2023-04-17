#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

//handle our signal.
void	handle_sigstp(int sig)
{
	printf("Stop not allowed\n");
}

void	handle_sigcont(int sig)
{
	printf("Input number: ");
	fflush(stdout);
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}
