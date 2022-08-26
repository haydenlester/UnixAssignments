#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int flag=0;

void handler(int);

int main(void)
{
    int i;
    char c;
    pid_t pid;
    int count=0;

    signal(SIGCHLD,handler);

    /*
     * create a child process.
     */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    printf("The pid return from fork is %d. Who am I, parent or child?\n",pid);

    if (pid == 0) {
        /*
         * This code executes in the child process
         * (fork returned zero).
         */
	count++;
	printf("This is the Child: My pid is %d, I am the Child of %d, count=%d\n", getpid(),getppid(), count);

    }
    else {
        /*
         * This code executes in the parent process.
         */
	count--;
	printf("This is the Parent:%d, my child is:%d,  my parent is:%d, count=%d\n", getpid(), pid, getppid(),count);
    }

    /*
     * This code executes in both processes (i.e.,
     * it gets executed twice).
     */
    printf("Executed in both processes: I am:%d, my child is:%d, my parent is:%d, count:%d\n",getpid(),pid, getppid(),count);
    printf("\n");
  
   if (flag ==0)
    pause();

   printf("I am:%d, my child %d is dead!!\n",getpid(),pid);
   return(0);
}

void handler(int sig)
{
 psignal(sig,"signal received:");
 flag=1;
}
