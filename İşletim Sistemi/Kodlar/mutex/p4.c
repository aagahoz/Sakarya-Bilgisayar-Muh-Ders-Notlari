#include <stdio.h>
#include <unistd.h>
int main( int argc, char **argv[] ) {
        int pid;
	int a=5;
	pid=fork();

	if(pid==0)
	{
	a=3;  
	printf( " %s %d %d\n", argv[1],argc,a );
	}
        else if(pid>0)
	{
	printf( " %s %d %d\n", argv[1],argc,a );
	}
        return 0;
}
