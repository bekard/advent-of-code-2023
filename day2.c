#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define RED_CUBES_COUNT 12
#define GREEN_CUBES_COUNT 13
#define BLUE_CUBES_COUNT 14

struct game_results
{
	int id;
	int red;
	int green;
	int blue;
};

static void parse_game(char* game, struct game_results* results)
{
	if(!game || !results)
	{
		return;
	}

	printf("game=%s", game);
	
	int num = 0;
	

	for(char* tokens = strtok(game, " ,.:"); tokens; tokens = strtok(NULL, "\t\n ,.:;"))
	{
		printf("token=%s\n", tokens);
		if(isdigit(tokens[0]))
		{
			num = atoi(tokens);
			results->id = results->id ? results->id : num;
			printf("isdigit\tnum=%d\n", num);
		}
		else if(strcmp(tokens, "red") == 0)
		{
			printf("red\tnum=%d\n", num);
			results->red += num;
		}
		else if(strcmp(tokens, "green") == 0)
		{
			printf("green\t num=%d\n", num);
			results->green += num;
		}
		else if(strcmp(tokens, "blue") == 0)
		{
			printf("blue\tnum=%d\n", num);
			results->blue += num;
		}
	}
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("Wrong number of arguments. Usage: day2 input_file\n");
		return 1;
	}

	char* input_path = argv[1];
	FILE* input_file = fopen(input_path, "r");

	if(!input_file)
	{
		printf("Can't open file \"%s\" for reading\n", input_path);
		return 1;
	}

	char buffer[256] = {0};
	struct game_results results;
	
	while(fgets(buffer, sizeof(buffer), input_file) != NULL)
	{
		memset(&results, 0, sizeof(results));
		parse_game(buffer, &results);

		printf("id=%d r=%d g=%d b=%d\n\n", results.id, results.red, results.green, results.blue);
		break;
	}


	fclose(input_file);
	return 0;
}
