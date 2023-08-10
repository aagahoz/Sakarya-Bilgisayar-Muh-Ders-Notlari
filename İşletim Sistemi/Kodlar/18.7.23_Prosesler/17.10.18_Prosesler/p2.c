// Fork örneği
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  int pid, pid_ebeveyn;

  pid_ebeveyn = getpid();
  printf("Ebeveyn pid = %d\n", pid_ebeveyn);

  pid = fork();

  if(pid == 0) { // yavru proses alanı
    printf("Ben yavru prosesim, benim pid değişkeni= %d\n", pid); // 0 yazacak
    printf("Ben yavru prosesim, benim = %d\n", getpid()); 
    printf("Ben yavru prosesim, benim ebeveyn pid = %d\n", getppid()); // xxxx değer
    while(1) ; // sonsuz döngü
  } else if(pid > 0){ // Burası ebeveyn
    printf("Ben ebeveyn prosesim, benim yavrunun pid = %d\n", pid);
    while(1) ; // sonsuz döngü
  } else if(pid < 0){
    printf("Fork sırasında hata oluştu\n");
  }
}
