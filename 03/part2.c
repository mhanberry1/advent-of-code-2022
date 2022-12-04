#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int priorities_sum = 0;
	FILE* input = fopen("input.txt", "r");
	char* line = NULL;
	size_t length = 0;
	int num_char;
	int sack_size = 'z' - 'A' + 1;
	bool rucksacks[3][sack_size];

	// Initialize rucksacks
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < sack_size; j++) rucksacks[i][j] = false;
	}
	
	int line_num = 0;
	while((num_char = getline(&line, &length, input)) != -1){
		
		// Populate rucksack
		for(int i = 0; i < sack_size; i++) rucksacks[line_num % 3][i] = false;
		for(int i = 0; i < num_char - 1; i++) rucksacks[line_num % 3][line[i] - 'A'] = true;

		// Check for badge
		if(line_num % 3 == 2){
			for(int i = 0; i < sack_size; i++){
				if(
					rucksacks[0][i] == true &&
					rucksacks[1][i] == true &&
					rucksacks[2][i] == true
				){
					int priority = (i < 26) ? i + 27 : i - ('a' - 'A') + 1;
					priorities_sum += priority;
					break;
				}
			}

		}

		line_num++;
	}
	
	printf("%d\n", priorities_sum);

	return 0;
}
