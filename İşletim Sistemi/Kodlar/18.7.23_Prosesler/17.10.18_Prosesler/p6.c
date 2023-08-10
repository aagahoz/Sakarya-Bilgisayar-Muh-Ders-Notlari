// fork, exec
#include <sys/types.h>
#include<stdio.h>
#include <unistd.h>

int main()
{
  int pid;

  printf("pid = %d\n", getpid());
  
  pid = fork();

  if(pid == 0) {
    printf("Burası yavru proses pid = %d\n", pid);
    printf("yavru pid = %d\n", getpid());
    printf("ebeveyn pid = %d\n", getppid());

    execlp("/usr/bin/xeyes", "xeyes", NULL);

    while(1) ;
  } else if(pid > 0){
    printf("Burası ebeveyn proses yavru pid = %d\n", pid);
    while(1) ;
  } else if(pid < 0)
    printf("fork hatası\n");


}
