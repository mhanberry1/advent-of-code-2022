#include <stdio.h>
#include <stdlib.h>

int main(){
	int top_three[] = {0, 0, 0};
	int top_three_total = 0;
	int current = 0;
	FILE* input = fopen("input.txt", "r");
	char* line;
	size_t length;

	while(getline(&line, &length, input) != -1){
		current = (line[0] != '\n') ? current + atoi(line) : 0;
		
		if(current > top_three[0]){
			top_three[2] = top_three[1];
			top_three[1] = top_three[0];
			top_three[0] = current;
		}else if(current > top_three[1]){
			top_three[2] = top_three[1];
			top_three[1] = current;
		}else if(current > top_three[2]){
			top_three[2] = current;
		}
	}

	for(int i = 0; i < 3; i++){
		top_three_total += top_three[i];
	}
	
	printf("%d\n", top_three_total);

	return 0;
}
