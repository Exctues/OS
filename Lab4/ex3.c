#include <stdio.h>
#include <string.h>
int  main(){
	char str[255];
	while(1){
		printf(">>> ");
		fgets(str, sizeof(str), stdin);
		if(str[0] == 'e'  && str[1] == 'x' && str[2] == 'i' && str[3] == 't'){
			break;					
		} 
		system(str);
	}
	return 0;
}
