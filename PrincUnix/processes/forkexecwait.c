#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/wait.h>


int
main(void)
{
    pid_t pid;
    pid_t cpid;
    char *args[4];

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
 sleep(20);
        execl("/bin/echo", "echo", "Today's", "date", "is:", NULL);

        /*
         * If the exec succeeds, we'll never get here.
         */
        perror("exec");
        exit(1);
    }

    /*
     * Wait for the child process to complete.  We
     * don't care about the termination status.
     */
//       sleep(30); // kill the child here and see how a zombie child looks
    while (wait((int *) 0) != pid)
        continue;

//    cpid=wait((int *) 0) ;
//    printf("cpid:%d\n",cpid);

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

