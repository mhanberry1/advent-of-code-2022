#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int priorities_sum = 0;
	FILE* input = fopen("input.txt", "r");
	char* line;
	size_t length;
	int num_char;
	
	while((num_char = getline(&line, &length, input)) != -1){
		int comp_size = 'z' - 'A';
		bool* compartment1 = malloc(comp_size);
		
		// Initialize compartment1
		for(int i = 0; i < comp_size; i++) compartment1[i] = false;
		
		// Populate compartment1
		for(int i = 0; i < num_char / 2; i++){
			compartment1[line[i] - 'A'] = true;
		}

		// Check for duplicates
		for(int i = num_char / 2; line[i] != '\0'; i++){
			if(compartment1[line[i] - 'A'] == true){
				int priority = (line[i] < 'a') ? line[i] - 'A' + 27: line[i] - 'a' + 1;
				priorities_sum += priority;
				break;
			}
		}
	}
	
	printf("%d\n", priorities_sum);

	return 0;
}
