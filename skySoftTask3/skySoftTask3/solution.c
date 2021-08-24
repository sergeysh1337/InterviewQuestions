#include<stdio.h>    
#include<stdlib.h>  
#include<math.h>
#pragma warning(disable : 4996)

void findMistakes(FILE* source,FILE* target)
{
	int line = 0;
	char* ptr;
	char buffer[100];
	int time, velocity, distance, result;

	for (line = 0; !feof(source); line++)
	{
		//pointer to the start of the line
		ptr = buffer;
		fgets(buffer, 100, source);
		//skipping the first line of the file
		if (line == 0)
			continue;
		//getting variables from the line 
		time = strtol(ptr, &ptr, 10);
		velocity = strtol(ptr + 1, &ptr, 10);
		distance = strtol(ptr + 1, &ptr, 10);
		//calculate the correct distance
			result = time * velocity * 3;
		//compate between two results
		if (result != distance)
		//write the line to the errors file, if it's not matching
			fputs(buffer, target);
	}
	fclose(source);
	fclose(target);
}



int main() {
	FILE* source;
	FILE* target;
	source = fopen("vehicle_data.txt", "r");
	target = fopen("errors.txt", "w");
	if (!source)
		return;
	findMistakes(source, target);
}