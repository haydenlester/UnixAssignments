#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void handler(int);

// Our global variable stopFlag
int stopFlag = 0;

void 
stop (int seconds)
{
	signal(SIGALRM, handler);
	alarm(seconds);
	pause();
//	sleep(seconds);
}

void
handler(int sig)
{
        static int count = 0;
	printf("Aah Nice!\n");
        count++;
        if(count >= 3)
            stopFlag = 1;
        return;
}

int main(int argc,char* argv[])
{
        while(stopFlag == 0){
	    printf("Stop and smell the roses for %d seconds\n",atoi(argv[1]));
	    stop(atoi(argv[1]));
        }
}
