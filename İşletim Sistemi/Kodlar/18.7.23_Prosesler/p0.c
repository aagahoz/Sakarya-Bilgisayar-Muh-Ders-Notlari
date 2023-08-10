// Fork örneği
//#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc, char** argv) {

  
 int pid,a=9;

 printf("pid = %d\n", getpid());
 printf("parent pid = %d\n", getppid()); 

 
 pid=fork();

 if(pid>0)
{
 
 printf("Merhaba burası ebeveyn\n");
printf("pid = %d\n", getpid());
printf("a = %d\n", a);
printf("pid deg = %d\n", pid);
a=1;

}
 else if (pid==0)

{
printf("Merhaba burası çocuk proses\n");
printf("pid = %d\n", getpid());
printf("a = %d\n", a);
printf("pid deg = %d\n", pid);
execlp("/usr/bin/xcalc", "xcalc", NULL);
}
else if(pid<0)


 return 0;
  
}
