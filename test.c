#include <stdio.h>
#include <string.h>
#include "dbg.h"
#include "sort.h"

#define LOG_FILE "./log.txt"

// returns OPERATION_SUCCESS if equal
int arr_cmp(int *arr1, int *arr2, size_t len)
{
	check(arr1 != NULL, "arr1 can't be null.");
	check(arr2 != NULL, "arr2 can't be null.");
	check(len > 0, "len must be greater than 0.");

	size_t i;
	for (i = 0; i < len; i++)
	{
		if (arr1[i] != arr2[i]) goto error; 
	}

	return OPERATION_SUCCESS;

error:
	return OPERATION_FAILURE;
}

int int_print_arr(int *arr, size_t len)
{
	size_t i;
	check(arr != NULL, "arr can't be null.");
	check(len > 0, "len must be greater than 0.");

	for (i = 0; i < len - 1; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d\n", arr[len - 1]);

	return OPERATION_SUCCESS;

error:
	return OPERATION_FAILURE;
}

int string_print_arr(char **arr, size_t len)
{
	size_t i;
	check(arr != NULL, "arr can't be null.");
	check(len > 0, "len must be greater than 0.");

	for (i = 0; i < len - 1; i++)
	{
		printf("%s, ", arr[i]);
	}
	printf("%s\n", arr[len - 1]);

	return OPERATION_SUCCESS;

error:
	return OPERATION_FAILURE;
}

int main(int argc, char *argv[])
{
	dbg_out = fopen(LOG_FILE, "a");
	check(dbg_out != NULL, "Failed to open file %s", LOG_FILE);
	
	int test1[] = { 1, 2, 0 };
	int expected1[] = {0, 1, 2};
	char *test2 = "BICEAFDGHKJ";
	char *expected2 = "ABCDEFGHIJK";
	char *test3[] = { "cat", "ca", "hello", "World", "MrBitShift" };
	char **test4 = test3;

	int **result1 = calloc(1, sizeof(int*));
	char **result2 = calloc(1, sizeof(char*));
	char ***result3 = calloc(1, sizeof(char**));
	char ***result4 = calloc(1, sizeof(char**));

	int_insertion_sort(test1, 3, result1);
	int_print_arr(*result1, 3);
	check(arr_cmp(expected1, *result1, 3) == OPERATION_SUCCESS, 
		"did not match.");
	
	char_insertion_sort(test2, result2);
	printf("%s\n", *result2);
	check(strcmp(expected2, *result2) == 0, "did not match.");

	string_insertion_sort(test3, 5, result3);
	string_print_arr(*result3, 5);

	string_lex_insertion_sort(test4, 5, result4);
	string_print_arr(*result4, 5);

	return OPERATION_SUCCESS;

error:
	log_err("Test failed.");
	return 1;
}
