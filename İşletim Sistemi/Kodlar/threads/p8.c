/*ipc_signal.c*/

#include<stdio.h>
#include<signal.h>


void hello(){
  printf("Hello World!\n");
}

int main(){

  pid_t cpid;
  pid_t ppid;

  //set handler for SIGUSR1 to hello()
  signal(SIGUSR1, hello);

  if ( (cpid = fork()) == 0){
    /*CHILD*/

    //get parent's pid
    ppid = getppid();

    //send SIGUSR1 signal to parrent
//The kill() system call is used by OS to send a termination signal to a process that urges the process to exit.
//However, a kill system call does not necessarily mean killing the process and can have various meanings.
    kill(ppid, SIGUSR1);
    exit(0);

  }else{
    /*PARENT*/

    //just wait for child to terminate
    wait(NULL);
  }

}

