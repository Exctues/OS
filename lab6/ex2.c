#include <stdio.h>
#include <unistd.h>
#include <string.h>

int pipe_data[2];
int pipe_size[2];

int main() {
    printf("PROGRAM STARTED\n");

    pipe(pipe_size);
    pipe(pipe_data);

    int res = fork();
    if (res == 0) {
        // Child
        sleep(3);
        char buffer[255];
        unsigned int data_size = 0;

        read(pipe_size[0], &data_size, sizeof(unsigned int));
        printf("received data_size = %d\n", data_size);

        read(pipe_data[0], &buffer[0], data_size);
        printf("word = '%s' and length = '%d' \n", buffer, data_size);

    } else {
        // Parent
        char word[] = "123456";
        int word_size = strlen(word) + 1;
        
        write(pipe_size[1], &word_size, sizeof(int));
        write(pipe_data[1], word, word_size);
    }
    return 0;
}
