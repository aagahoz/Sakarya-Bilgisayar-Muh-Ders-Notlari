// Fork örneği
//#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc, char** argv) {

  
 int pid;

 printf("pid = %d\n", getpid());
 printf("parent pid = %d\n", getppid()); 

 pid=fork();
 
 printf("Merhaba, pid degeri:%d\n",pid);
 //wait(NULL);  


   return 0;
  
}
