// Pipe

#include <stdio.h>
#include <unistd.h>


int main()
{
  int pid;
  int pd[2];

  pipe(pd);

  pid = fork();

  // Yavru ----> Ebeveyn

  if(pid > 0) { // Ebeveyn

    char buf[10];
    close(pd[1]); // Yazma ucu kapatılsın
    read(pd[0], buf, 8);
    printf("---Okundu: %s\n", buf);

  } else if(pid == 0) { // Yavru

    close(pd[0]); // Okuma ucu kapatılsın
    write(pd[1], "Merhaba", 8);

  }

}
