/**
 * Figure 3.31
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("1: %d\n",getpid());
        printf("1: %d\n",getppid());
	fork();

	printf("2: %d\n",getpid());
        printf("2: %d\n",getppid());
	fork();

	printf("3: %d\n",getpid());
        printf("3: %d\n",getppid());
	//fork();
	
	//printf("4: %d\n",getpid());

	return 0;
}
