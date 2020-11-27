#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void sighandler(int signo) {
	if (signo == SIGINT) {
		printf("Program exited due to SIGINT\n");
		exit(0);
	}

	if (signo == SIGUSR1) {
		printf("Detected SIGUSR1. My parent ID is: %d\n", getppid());
	}
}

int main() {
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);

	while (1) {
		printf("My ID is: %d\n", getpid());
		sleep(1);
	}

	return 0;
}