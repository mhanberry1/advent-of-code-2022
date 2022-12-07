#include <stdio.h>
#include <stdlib.h>

int main(){
	int result = 0;
	FILE* input = fopen("input.txt", "r");
	char* line = NULL;
	size_t length = 0;
	int num_chars;

	while((num_chars = getline(&line, &length, input)) != -1){
		int left1 = -1;
		int left2 = -1;
		int right1 = -1;
		int right2 = -1;
		int start = 0;

		for(int i = 0; i < num_chars; i++){
			if(line[i] == '-' || line[i] == ','){
				line[i] = '\0';
				
				if(left1 == -1) left1 = atoi(line + start);
				else if(right1 == -1) right1 = atoi(line + start);
				else if(left2 == -1) left2 = atoi(line + start);

				start = i + 1;
			}
		}

		right2 = atoi(line + start);

		if(
			(left1 <= left2 && right1 >= right2) ||
			(left2 <= left1 && right2 >= right1)
		) result++;
	}

	printf("%d\n", result);

	return 0;
}
