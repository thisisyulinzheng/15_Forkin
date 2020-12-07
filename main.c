#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
	
	printf("We're about to fork!\n");
	int f, status;

	f = fork();

	if (f) {
		f = fork();
	}

	if (f) {
		printf("Parent Process ID: %d\n", getpid());

		int id = wait(&status);

		printf("Child Finished | Child Pid: %d, Child ran for: %d seconds\n", id, WEXITSTATUS(status));

		printf("Parent Finished; Ending Parent Process...\n");

		return 0;
	}

	else {
		printf("Child Process ID: %d\n", getpid());

		srand(time(NULL) * getpid());

		int sleep_time = (rand() % 9) + 2;
		
		sleep(sleep_time);

		printf("Forked Process Finished; Slept for %d seconds\n", sleep_time);

		return sleep_time;	
	}
}