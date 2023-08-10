// Fork örneği
//#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc, char** argv) {

  
 int pid,pid2;

 printf("pid = %d\n", getpid());
 printf("parent pid = %d\n", getppid()); 
 pid=fork();
 
if(pid>0)
{
 //fork();
 printf("Burası ebeveeyn proses\n");
 printf("pid = %d\n", pid);	
 printf("pid child = %d\n", getpid());
 printf("pid parent = %d\n", getppid());
} else if(pid==0)
{
printf("Burası child proses\n");
 printf("pid = %d\n", pid);	
 printf("pid child = %d\n", getpid());
 printf("pid parent = %d\n", getppid());
}




   return 0;
  
}
