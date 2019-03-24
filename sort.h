#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dbg.h"

int lower(char *in, size_t len, char **out)
{
	int i;
	
	check(in != NULL, "in can't be null.");
	check(len > 0, "len must be greater than 0.");
	check(out != NULL, "out cannot be null.");

	*out = calloc(len + 1, sizeof(char));

	for (i = 0; i < len; i++)
	{
		(*out)[i] = tolower(in[i]);
	}

	return OPERATION_SUCCESS;

error:
	return OPERATION_FAILURE;
}

int int_insertion_sort(int *arr, size_t arr_len, int **out)
{
	int i;
	int b;
	int current;

	check(arr != NULL, "arr can't be null.");
	check(arr_len > 0, "len must be greater than 0.");
	check(out != NULL, "out must not be null.");

	*out = calloc(arr_len, sizeof(int));
	memcpy(*out, arr, arr_len * sizeof(int));
	
	for (i = 1; i < arr_len; i++)
	{
		current = (*out)[i];
		
		for (b = i - 1; b >= 0 && (*out)[b] > current; b--)
		{
			(*out)[b + 1] = (*out)[b];
		}
		(*out)[b + 1] = current;
	}

	return OPERATION_SUCCESS;

error:
	return OPERATION_FAILURE;
}

int char_insertion_sort(char *arr, char **out)
{
	int i;
	int b;
	char current;
	size_t arr_len = strlen(arr);

	check(arr != NULL, "arr can't be null.");
	check(arr_len > 0, "len must be greater than 0.");
	check(out != NULL, "out must not be null.");

	*out = calloc(arr_len + 1, sizeof(char)); // + 1 for null
	memcpy(*out, arr, arr_len * sizeof(char));
	
	for (i = 1; i < arr_len; i++)
	{
		current = (*out)[i];
		
		for (b = i - 1; b >= 0 && (*out)[b] > current; b--)
		{
			(*out)[b + 1] = (*out)[b];
		}
		(*out)[b + 1] = current;
	}

	return OPERATION_SUCCESS;

error:
	return OPERATION_FAILURE;
}

int string_insertion_sort(char **arr, size_t arr_len, char ***out)
{

	int i;
	int b;
	char *current;

	check(arr != NULL, "arr can't be null.");
	check(*arr != NULL, "members of arr can't be null.");
	check(arr_len > 0, "arr_len must be greater than 0.");
	check(out != NULL, "out must not be null.");

	*out = calloc(arr_len, sizeof(char*));
	memcpy(*out, arr, arr_len * sizeof(char*));
	
	for (i = 1; i < arr_len; i++)
	{
		current = (*out)[i];
		
		for (b = i - 1; b >= 0; b--)
		{
			if (strcmp((*out)[b], current) <= 0)
				break;
			// element is greater than current
			// push element forward
			(*out)[b + 1] = (*out)[b];
		}
		(*out)[b + 1] = current;
	}

	return OPERATION_SUCCESS;

error:
	return OPERATION_FAILURE;
}

int string_lex_insertion_sort(char **arr, size_t arr_len, char ***out)
{	
	int i;
	int b;
	char **lower_case;
	char **compare_lower;

	check(arr != NULL, "arr can't be null.");
	check(*arr != NULL, "members of arr can't be null.");
	check(arr_len > 0, "arr_len must be greater than 0.");
	check(out != NULL, "out must not be null.");

	*out = calloc(arr_len, sizeof(char*));
	memcpy(*out, arr, arr_len * sizeof(char*));
	
	for (i = 1; i < arr_len; i++)
	{
		char* current = (*out)[i];
		lower_case = calloc(1, sizeof(char*));
		check(lower(current, strlen(current), lower_case) == 0,
			"failure in lower.");
		
		for (b = i - 1; b >= 0; b--)
		{
			compare_lower = calloc(1, sizeof(char*));
			check(lower(
				(*out)[b], strlen((*out)[b]), compare_lower)
				== 0,
				"failure in lower.");
			if (strcmp(*compare_lower, *lower_case) <= 0)
				break;
			// element is greater than current
			// push element forward
			(*out)[b + 1] = (*out)[b];
		}
		(*out)[b + 1] = current;
	}

	free(*lower_case);
	free(lower_case);
	free(*compare_lower);
	free(compare_lower);

	return OPERATION_SUCCESS;

error:
	free(*lower_case);
	free(lower_case);
	free(*compare_lower);
	free(compare_lower);

	return OPERATION_FAILURE;
}
