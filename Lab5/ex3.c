#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define PRODUCER_ID 0
#define CONSUMER_ID 1

#define ARRAY_SIZE  10
#define AMOUNT_ITERATION  100

int buffer[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int count = 0;
int wait_bit = 0;

void printb() {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void *producer_thread(void *param) {
    printf("Producer thread started\n");

    for (int i = 1; i <= AMOUNT_ITERATION; ++i) {
        while (1) {
			printf("From Producer:\n");
			printb();
			
			if(count == 9){
            	wait_bit = 1;
				printf("Producer fall asleep\n");
            	sleep(0.8);
				printf("Producer awakened\n");
				//fflush(stdout);
			}else{break;}
        }
        buffer[count] = i;
        count++;
    }

    pthread_exit(0);
}

void *consumer_thread(void *param) {
    printf("Consumer thread started\n");

    for (int i = 1; i <= AMOUNT_ITERATION; ++i) {
        while (1) {
			printf("From Customer:\n");
			printb();
			if(count == 0){
				printf("Consumer fall asleep\n");
		    	sleep(0.8);
				printf("Consumer awakened\n"); 
			}
            else{break;}
					
        }
        buffer[count] = -1;
        count--;

    }

    pthread_exit(0);
}

int main() {
    pthread_t thread_prod, thread_cons;
    int id_prod = PRODUCER_ID;
    int id_cons = CONSUMER_ID;
    int ret_prod = pthread_create(&thread_prod, NULL, producer_thread, &id_prod);
    int ret_cons = pthread_create(&thread_cons, NULL, consumer_thread, &id_cons);

    //
    pthread_join(thread_cons, NULL);
    pthread_join(thread_prod, NULL);

    if (ret_prod == 0) {
        printf("Producer finished successfully\n");
    } else {
        printf("Producer failed\n");
    }
    if (ret_cons == 0) {
        printf("Consumer finished successfully\n");
    } else {
        printf("Consumer failed\n");
    }

    return 0;
}
