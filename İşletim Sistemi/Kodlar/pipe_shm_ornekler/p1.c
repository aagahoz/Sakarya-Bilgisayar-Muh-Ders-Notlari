// Pipe örneği
#include<stdio.h> 
#include<stdlib.h> 
#include<fcntl.h> 
#include<unistd.h>

int main()
{
  int pid, ret;
  int pd[2];

  ret = pipe(pd);
  if(ret < 0){
    printf("Pipe error\n");
    exit(1);
  }


  pid = fork();
  if(pid > 0){ // Ebeveyn - yazan
    close(pd[0]); //okuma pasif
    write(pd[1], "MerhabaSakaryaUniversitesi", 44);
    printf("-----Ebeveyn yazdı-----\n"); 
  } else if(pid == 0){ // Yavru okuyan
    
    char buf[10];
    close(pd[1]); //yazma pasif
    read(pd[0], buf, 8); //okuma aktif
    printf("-----Yavru okudu-----\n"); 
    printf("okunan = %s\n", buf);
  }


}
