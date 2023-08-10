// Senkronizasyon
#include<stdio.h>
#include<unistd.h>

int main()
{
  int pid;

  pid = fork();

  if(pid == 0) { // Yavru
    while(1){
      printf("%c\n", 'B');
      sleep(1);
    }
  } else if(pid > 0) { // Ebeveyn
    while(1){
      printf("%c\n", 'A');
      sleep(1);
    }
  }
}
