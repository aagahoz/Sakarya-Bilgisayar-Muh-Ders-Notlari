// Pipe örneği
#include<stdio.h> 
#include<stdlib.h> 
#include<fcntl.h> 
#include<unistd.h>
#include<string.h>

int main()
{
int  pd[2];  char  x[11], y[11];
if (pipe(pd) == -1) {
fprintf(stderr, "Failed pipe.\n"); exit(1);
}
strcpy(x, "0123456789");
write(pd[1], x, 8);
read(pd[0], y, 8);
printf("%s\n", y);

}
