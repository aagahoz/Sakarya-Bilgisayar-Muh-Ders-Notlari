#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main( int argc, char *argv[], char *env[] )
{
   pid_t my_pid, parent_pid, child_pid;
   int status;

/* get and print my pid and my parent's pid. */

   my_pid = getpid();    
   parent_pid = getppid();
   printf("\n Parent: my pid is %d\n\n", my_pid);
   printf("Parent: my parent's pid is %d\n\n", parent_pid);

/* print error message if fork() fails */
   if((child_pid = fork()) < 0 )
   {
      perror("fork failure");
      exit(1);
   }
fork();
/* fork() == 0 for child process */

   if(child_pid == 0)
   {  printf("\nChild: I am a new-born process!\n\n");
      my_pid = getpid();    parent_pid = getppid();
      printf("Child: my pid is: %d\n\n", my_pid);
      printf("Child: my parent's pid is: %d\n\n", parent_pid);
     
      printf("Child: 5'ten geriye sayıp kapanacağım \n\n");
      sleep(2);     
      printf("5\n");
      sleep(2); 
      printf("4\n");
      sleep(2);
      printf("3\n");
      sleep(2);
      printf("2\n"); 
       sleep(2);
      printf("1\n");
      sleep(2);
      printf("0\n"); 
      sleep(2);
      _exit(1);
   }
/*
 * parent process
 */
   else
   {
      printf("\nParent: I created a child process.\n\n");
      printf("Parent: my child's pid is: %d\n\n", child_pid);
      //system("ps -acefl | grep ercal");  printf("\n \n");
      //wait(&status); /* can use wait(NULL) since exit status
      //                 from child is not used. */
      printf("\n Parent: my child is dead. I am going to leave.\n \n ");
   }

   return 0;
}
