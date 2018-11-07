#include <stdio.h>
#include <string.h>

int main(){
	char a[255];
	fgets(a, sizeof a, stdin);
	
	int n = strlen(a)-1;
	if(n == 0){
		printf("Incorrect. Please enter string which length more than 0");
	}
	else{
		for (int i = n-1; i >= 0; i--){
			printf("%c",a[i]);
		}
	}
	printf("\n");
	return 0;
}
