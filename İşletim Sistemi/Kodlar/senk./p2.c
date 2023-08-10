// Senkronizasyon
#include<stdio.h>
#include<unistd.h>
#include <semaphore.h>
#include <fcntl.h>

int main()
{
  int pid;
  sem_t *s1, *s2;

  //sem_init(s1, 1, 0);  //unnamed
  //sem_init(s2, 0, 0);  //unnamed
  sem_unlink("mysem1");
  sem_unlink("mysem2");
  s1 = sem_open("mysem1", O_CREAT | O_EXCL, 0644, 0);
  s2 = sem_open("mysem2", O_CREAT | O_EXCL, 0644, 1);

  pid = fork();

  if(pid == 0) { // Yavru
    while(1){
      sem_wait(s2); //--------------------------
      printf("%c\n", 'B');
      //printf("%c\n", 'B');
      sleep(1);
      sem_post(s1); //--------------------------
    }
  } else if(pid > 0) { // Ebeveyn
    while(1){
      sem_wait(s1); //--------------------------
      printf("%c\n", 'A');
      sleep(1);
      sem_post(s2); //--------------------------
      
    }
  }
  sem_unlink("mysem1");
  sem_unlink("mysem2");
  sem_destroy(s1);
  sem_destroy(s2);
  return 0;
}
