// Fork, exec örneği
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  int pid, pide;

  pide = getpid();
  printf("Ebeveyn pid = %d\n", pide);

  pid = fork();

  if(pid == 0) { // yavru proses alanı
    printf("Ben yavru prosesim, benim pid = %d\n", pid);
    printf("Ben yavru prosesim, benim ebeveyn pid = %d\n", getppid());
    execlp("/usr/bin/xcalc", "xcalc", NULL);
    while(1) ; // sonsuz döngü
  } else if(pid > 0){ // Burası ebeveyn
    printf("Ben ebeveyn prosesim, benim yavrunun pid = %d\n", pid);
    while(1) ; // sonsuz döngü
  } else if(pid < 0){
    printf("Fork sırasında hata oluştu\n");
  }
}
