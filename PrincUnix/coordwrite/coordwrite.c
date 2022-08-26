#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sigusr_handler(int);
void sigint_handler(int);
//our exit flag
int exitF = 0;

int main(int argc, char *argv[]){
	
	// Step 1: P forks C, prints its PID and child's PID, opens a file given a CL argument, writes a line to file, closes file, sleeps for 2 seconds, sends SIGUSR1 to C and waits
	int pid = fork();
	
	// Our messages
	char msg1[] = "I AM THE PARENT\n";
	char msg2[] = "I am the Child\n";
	
	// Init our count
	int count = 0;
	
	// This will be our file ptr
	FILE *fptr;
	
	// Set up signal handlers
	if (signal(SIGUSR1, sigusr_handler) == SIG_ERR) {
		fprintf(stderr, "cannot set handler for SIGUSR1\n");
		exit(1);
    }
	
	if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        fprintf(stderr, "cannot set handler for SIGINT\n");
        exit(1);
    }
	
	while(1){
		if(pid == 0){
			pause();
			printf("PID of child(me): %d\nPID of parent:%d\n", getpid(), getppid());
			
			fptr = fopen(argv[1], "a");
			fprintf(fptr, "%s", msg2);
			fclose(fptr);
			
			sleep(2);
			
			if(count < 5){
				kill(getppid(), 10);
				count++;
			}else
				kill(getppid(), 2);
			if(exitF)
				exit(1);
		}else{
			printf("PID of parent(me): %d\nPID of child: %d\n", getpid(), pid);
			
			//open file
			fptr = fopen(argv[1], "a");
			fprintf(fptr, "%s", msg1);
			fclose(fptr);
			
			//sleep two seconds
			sleep(2);
			
			//send sigusr1
			if(count < 5){
				kill(pid, 10);
				count++;
			}else
				kill(pid, 2);
			
			if(exitF)
				exit(1);
			//Wait for next signal
			pause();
		}
	}
}

void sigusr_handler(int sig)
{
	// Does nothing but avoid termination, counter for this exists in the program itself
}

void sigint_handler(int sig) {
	static int count = 0;
	count++;
	if(count >= 3){
		exitF = 1;
	}
}