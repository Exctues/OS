#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *start(void *param) {
    printf("Hello from %d.\n", *((int *)param));
    pthread_exit(0);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        pthread_t thread;
        int id = i;
        pthread_create(&thread, NULL, start, &i);
		pthread_join(thread, NULL);
        printf("Thread %d finished.\n", id);

    }
	return 0;    
}	
