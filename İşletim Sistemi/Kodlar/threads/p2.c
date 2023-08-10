// Pthread örneği
#include<stdio.h>
#include<pthread.h>

#define N 5

int s = 28; // Paylaşılan değişken

void task(int *a)
{
  int b = *a;
  printf("Merhaba burası thread a = %d\n", b);
  pthread_exit(0);
}

int main()
{
  pthread_t tid[N]; //thread dizisi
  pthread_attr_t attr;
  int i;


  pthread_attr_init(&attr);
  
  for(i = 0; i < N; i++) 
    {
pthread_create(&(tid[i]), &attr, (void *) &task, &i);
 pthread_join(tid[i], NULL);
}	
  //wait for the thread to exit
  //for(i = 0; i < N; i++)  
    

  pthread_exit(0);

  return 0;
}
