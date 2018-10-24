#include <stdio.h>
// fork will return 0 for child processor and real PID of new(child) processor
int n = 100;

void main(){
	int pid = fork();
	if(pid == 0)
		printf("hello from child %d - %d\n", pid, n);
	else{
		printf("Hello from parent %d - %d\n", pid,n);		
	}
	
}
