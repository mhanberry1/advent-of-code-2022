#include <stdio.h>

int choice_score(char choice){
	if(choice == 'X') return 1;
	if(choice == 'Y') return 2;
	if(choice == 'Z') return 3;
}

int outcome_score(char opponent, char choice){
	if(opponent == 'A'){
		if(choice == 'X') return 3;
		if(choice == 'Y') return 6;
		if(choice == 'Z') return 0;
	}
	if(opponent == 'B'){
		if(choice == 'X') return 0;
		if(choice == 'Y') return 3;
		if(choice == 'Z') return 6;
	}
	if(opponent == 'C'){
		if(choice == 'X') return 6;
		if(choice == 'Y') return 0;
		if(choice == 'Z') return 3;
	}
}

int main(){
	int total = 0;
	FILE* input = fopen("input.txt", "r");
	char* line;
	size_t length;
	
	while(getline(&line, &length, input) != -1)
		total += choice_score(line[2]) + outcome_score(line[0], line[2]);

	printf("%d\n", total);

	return 0;
}
