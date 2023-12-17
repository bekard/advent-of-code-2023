#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define NOT_DEFINED -1

static bool is_string_digit(const char* str, const char* digit)
{
	size_t str_length = strlen(str);
	size_t digit_length = strlen(digit);

	return str_length < digit_length ? false : memcmp(str, digit, digit_length) == 0;
}

static int get_digit(const char* str)
{
	if(str)
	{
		if(isdigit(str[0]))
		{
			return str[0] - '0';
		}

		if(is_string_digit(str, "one"))
		{
			return 1;
		}

		if(is_string_digit(str, "two"))
		{
			return 2;
		}

		if(is_string_digit(str, "three"))
		{
			return 3;
		}

		if(is_string_digit(str, "four"))
		{
			return 4;
		}

		if(is_string_digit(str, "five"))
		{
			return 5;
		}

		if(is_string_digit(str, "six"))
		{
			return 6;
		}

		if(is_string_digit(str, "seven"))
		{
			return 7;
		}

		if(is_string_digit(str, "eight"))
		{
			return 8;
		}

		if(is_string_digit(str, "nine"))
		{
			return 9;
		}
	}


	return NOT_DEFINED;
}


static int get_calibration(const char* str, size_t size)
{
	int first = NOT_DEFINED;
	int second = NOT_DEFINED;
	
	for(size_t i = 0; str[i] != '\0' &&  i < size; i++)
	{
		int digit = get_digit(str + i);
		if(digit != NOT_DEFINED)
		{
			first = first == NOT_DEFINED ? digit * 10 : first;
			second = digit;
		}
	}

	return first + second;
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("Wrong number of arguments. Usage: day1 input_file\n");
		return 1;
	}

	char* input_path = argv[1];
	FILE* input_file = fopen(input_path, "r");

	if(!input_file)
	{
		printf("Can't open file \"%s\" for reading\n", input_path);
		return 1;
	}

	char buffer[64] = {0};
	int calibration_sum = 0;
	
	while(fgets(buffer, sizeof(buffer), input_file) != NULL)
	{
		int calibration = get_calibration(buffer, sizeof(buffer));
		printf("%d\t%s", calibration, buffer);
		calibration_sum += calibration;
	}

	printf("Calibration sum is %d\n", calibration_sum);

	fclose(input_file);
	return 0;
}
