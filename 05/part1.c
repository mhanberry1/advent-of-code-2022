#define NUM_STACKS 9
#define MAX_STACK_LEN 60

#include <stdio.h>
#include <stdlib.h>

char stacks[NUM_STACKS][MAX_STACK_LEN] = {"", "", "", "", "", "", "", "", ""};

void add_to_stack(int stack_num, char crate){
	for(int i = 0; i < MAX_STACK_LEN; i++){
		if(stacks[stack_num][i] == '\0'){
			stacks[stack_num][i] = crate;
			stacks[stack_num][i + 1] = '\0';
			break;
		}
	}
}

char remove_from_stack(int stack_num){
	char crate = '\0';
	
	for(int i = 0; i < MAX_STACK_LEN; i++){
		if(stacks[stack_num][i] == '\0'){
			if(i == 0) break;

			crate = stacks[stack_num][i - 1];
			stacks[stack_num][i - 1] = '\0';
			break;
		}
	}
	
	return crate;
}

void parse_stack_definition(char *line, int num_chars){
	for(int i = 1; i < num_chars; i += 4){
		if(line[i]) continue;

		int stack_idx = i % 4 - 1;
		char crate = line[i];

		add_to_stack(stack_num, crate);
	}
}

void parse_movement_instructions(char *line, int num_chars){
	for(int i = 0; i < num_chars; i++){
		
	}
}

int main(){
	char* result[9];
	input = fopen("test.txt", "r");
	char* line;
	int length;
	enum state = {stack_def = 0, instructions = 1}
	
	while((char* num_chars = getline(&line, &length, input)) != -1){
		if(state == stack_def) parse_stack_definition(line, num_chars);
		if(state == instructions) parse_movement_instructions(line, num_chars);
	}

	return 0;
}
