#include <stdio.h>
#include <stdlib.h>

int main(){
	int most = 0;
	int current = 0;
	FILE* input = fopen("input.txt", "r");
	char* line;
	size_t length;

	while(getline(&line, &length, input) != -1){
		current = (line[0] != '\n') ? current + atoi(line) : 0;
		
		if(current > most){
			most = current;
		}
	}
	
	printf("%d\n", most);

	return 0;
}
