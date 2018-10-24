#include <stdio.h>
#include <stdlib.h>

const int AGESIZE = 8;
int counter = 0;

void debug() {
    printf("KEK\n");
    fflush(stdin);
}

int find(int **a, int size, int elem) {
    for (int i = 0; i < size; i++) {
        if (a[i][0] == elem) {
            return i;
        }
    }
    return -1;
}

int aging(int **a, int size) {
    int minInd = 0;
    int minSum = 10005000;
    for (int i = 0; i < size; i++) {
        int curSum = 0;
        for (int j = AGESIZE - 1; j > 0; j--) {
            curSum += a[i][j] * (1 << (AGESIZE - j));
        }
        if (curSum < minSum) {
            minSum = curSum;
            minInd = i;
        }
    }
    return minInd;
}

void setR(int **a, int size, int pos) {
    //shift and put zeroes everywhere
    for (int i = 0; i < size; i++) {
        for (int j = AGESIZE - 1; j > 1; j--) {
            a[i][j] = a[i][j - 1];
        }
    }

    //set R on the corresponding position
    a[pos][1] = 1;
}


void main(void) {
    int n, hits = 0, miss = 0;

    //Reading number of frames
    printf("Write the number of page: ");
    scanf("%d", &n);
    printf("\n");

    freopen("Lab 09 input.txt", "r", stdin);
    
    //Init 2d array
    int **a = malloc(sizeof(int *) * n);

    //set zero all ages
    for (int i = 0; i < n; i++) {
        a[i] = malloc(sizeof(int) * AGESIZE);
        for (int j = 0; j < AGESIZE; ++j) {
            a[i][j] = 0;
        }
    }

    //processing
    while (1) {
        int elem = -1;
        scanf("%d", &elem);

        if (elem == EOF)
            break;
        printf("elem = %d\n", elem);
        int R_index = 0;

        if (counter < n) {
            miss++;
            a[counter][0] = elem;
            R_index = counter;
        } else {
            int pos = find(a, n, elem);
            if (pos == -1) {
                miss++;

                int toDel = aging(a, n);
                a[toDel][0] = elem;
                R_index = toDel;
            } else {
                hits++;
                R_index = pos;
            }
        }


        setR(a, n, R_index);
        counter++;
    }

    //final output
    printf("hits = %d\n", hits);
    printf("miss = %d\n", miss);

    printf("hit/miss ratio = %f\n", ((double) hits / miss));
}