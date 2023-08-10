// Fork örneği
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int value = 5;
int main()
{
  int pid=8;
  int pid_ebeveyn;
  int value2 = 10;
  pid_ebeveyn = getpid();
  printf("Ebeveyn pid = %d\n", pid_ebeveyn);

  pid = fork();

  if(pid == 0) { // yavru proses alanı
    printf("Ben yavru prosesim, benim pid değişkeni= %d\n", pid); // 0 yazacak
    printf("Ben yavru prosesim, benim value değişkeni= %d\n", value); // 5 yazacak
    printf("Ben yavru prosesim, benim value2 değişkeni= %d\n", value2); // 10 yazacak
    printf("Ben yavru prosesim, benim = %d\n", getpid()); 
    printf("Ben yavru prosesim, benim ebeveyn pid = %d\n", getppid()); // xxxx değer
    while(1) ; // sonsuz döngü
  } else if(pid > 0){ // Burası ebeveyn
    printf("Ben ebeveyn prosesim, benim yavrunun pid = %d\n", pid);
    printf("Ben ebeveyn prosesim, benim value değişkeni= %d\n", value); // 5 yazacak
    printf("Ben ebeveyn prosesim, benim value2 değişkeni= %d\n", value2); // 10 yazacak
    while(1) ; // sonsuz döngü
  } else if(pid < 0){
    printf("Fork sırasında hata oluştu\n");
  }
}
