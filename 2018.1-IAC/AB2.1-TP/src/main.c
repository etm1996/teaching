#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main (int argc, char *argv[], char *envp[]) {

int i;
int pid = fork(); /*Process ID and creates a children process using fork()*/
char commandcpu[100]; /*array for store the command string for cpu usage*/
char commandmem[100]; /*array for store the command string for memory usage*/
clock_t initialtime,finaltime;



if ( pid < 0 ) { /*Fork went wrong, and process failed*/
	perror ("Erro: ") ;
	exit (-1) ;
}
else if( pid > 0 ) /*Father(Parent) process*/
{
	sprintf(commandcpu, "%s%d%s", "ps -p ", pid, " -o %cpu | grep -v %CPU");/*Command string for cpu usage*/
    sprintf(commandmem, "%s%d%s", "pmap -x ", pid," | grep total | awk '{print $3}'");/*Command string for memory usage*/
     for(i = 0; i < 10; i++) {
     		printf("PID: %d\n", pid);
           	printf("Current CPU(%%) Usage:\n");
            system(commandcpu);
            printf("Total memory usage(KB)");
            system(commandmem);
            printf("---------\n");
            sleep(1);
        }
        kill(pid, SIGKILL);/*Kill the process*/
}
else /*Child process*/
{
	if(strcmp(argv[1], "ucp") == 0) { /*Uses CPU*/
		    for(;;) {
		    }
		}
         if(strcmp(argv[1], "ucp-mem") == 0) {/*Uses CPU & Memory*/
        double pasttime; /*For clocking purposes*/
        initialtime = clock();/*Starting time*/
        for (;;) {
        finaltime = clock();/*Finishing time*/
        pasttime = (double)(finaltime - initialtime) / CLOCKS_PER_SEC; /*Calculate how much time passed*/
        if (pasttime <= 10){/*Works for 10 seconds*/
              malloc(10*sizeof(int));
            }

            }
		}

}

printf ("Tchau !\n") ;
exit(0) ; /*End of process*/

}
