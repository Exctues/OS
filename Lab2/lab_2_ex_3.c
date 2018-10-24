#include <stdio.h>

int main(int argc, char *argv[]){
	int n;
	if(sscanf(argv[1], "%d", &n) != 1){
	 	return 1;
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-i; j++){
			printf(" ");
		}
		for (int j = 0; j < 1 + i*2; j++){
			printf("*");		
		}
		for (int j = 0; j < n-i; j++){
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
