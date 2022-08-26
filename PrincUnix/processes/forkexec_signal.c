#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int);
int flag=0;

int
main(void)
{
    pid_t pid;
    char *args[4];

    signal(SIGCHLD,handler);

    /*
     * Create a child process.
     */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        /*
         * This code executes in the child process
         * (fork returned zero).
         */
        execl("/bin/echo", "echo", "Today's", "date", "is:", NULL);

        /*
         * If the exec succeeds, we'll never get here.
         */
        perror("exec");
        exit(1);
    }

    /* Parent is doing something, without thinking of the child
     */

	while(flag ==0)
		pause();

    /*
     * This code executes in the parent process.
     */
    args[0] = "date";
    args[1] = "+%A, %B %d, %Y";
    args[2] = NULL;

    execv("/bin/date", args);

    /*
     * If the exec succeeds, we'll never get here.
     */
    perror("exec");
    exit(1);
}

void handler(int sig)
{

    psignal(sig, "Signal Received:");
    flag = 1;
}
