#include <stdio.h>

int choice_score(char opponent, char outcome){
	if(opponent == 'A'){
		if(outcome == 'X') return 3;
		if(outcome == 'Y') return 1;
		if(outcome == 'Z') return 2;
	}
	if(opponent == 'B'){
		if(outcome == 'X') return 1;
		if(outcome == 'Y') return 2;
		if(outcome == 'Z') return 3;
	}
	if(opponent == 'C'){
		if(outcome == 'X') return 2;
		if(outcome == 'Y') return 3;
		if(outcome == 'Z') return 1;
	}
}

int outcome_score(char outcome){
	if(outcome == 'X') return 0;
	if(outcome == 'Y') return 3;
	if(outcome == 'Z') return 6;
}

int main(){
	int total = 0;
	FILE* input = fopen("input.txt", "r");
	char* line;
	size_t length;
	
	while(getline(&line, &length, input) != -1)
		total += choice_score(line[0], line[2]) + outcome_score(line[2]);

	printf("%d\n", total);

	return 0;
}
