// /*
//  * Figure 3.30
//  */

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int value = 5;

// int main()
// {
// 	pid_t pid;

// 	pid = fork();
	
// 	if (pid == 0) { /* child process */
// 		value += 15;
// 		return 0;
// 	}
// 	else if (pid > 0) { /* parent process */
// 		wait(NULL);
// 		printf ("PARENT: value = %d\n",value); /* LINE A */
// 		return 0;
// 	}
// }


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    int item = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == BUFFER_SIZE) {
            pthread_cond_wait(&cond_producer, &mutex);
        }

        buffer[count++] = item++;
        printf("Producer produced: %d\n", item);

        pthread_cond_signal(&cond_consumer);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            pthread_cond_wait(&cond_consumer, &mutex);
        }

        int item = buffer[--count];
        printf("Consumer consumed: %d\n", item);

        pthread_cond_signal(&cond_producer);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
