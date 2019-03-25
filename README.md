# Sort.h
## Data sorting tools for c and c++
---
### Features:
 - Ability to sort characters, strings, and integers using the insertion sort algorithm.
 - Easy to use error reporting.

### Usage:

---

#### `int int_insertion_sort(int *arr, size_t arr_len, int **out)`

##### Description:
Sorts an array of integers from smallest to largest using insertion sort.

##### Parameters: 
 - `arr`: The array of integers to sort.
 - `arr_len`: The length of arr.
 - `out`: A pointer to an array of integers used to pass back the return value. 
     - Note: `out` should point to `NULL` but should not be `NULL`. If `out` does not point to `NULL`, then it is up to the user to free what `out` points to prior to calling this function.

##### Return Value:
 - returns `0` on success and anything else on failure.
    
##### Example:
```c
int rc;
int test[] = {1, 2, 0};
size_t test_len = 3;
int **result = calloc(1, sizeof(int*));

printf("before sort: %d %d %d\n", test[0], test[1], test[2]);
rc = int_insertion_sort(test, test_len, result);
if (rc != 0)
{
    printf("Failure in int_insertion_sort. Error: \"%s\"", sort_get_err());
    exit(1);
}
printf("after sort: %d %d %d\n", (*result)[0], (*result)[1], (*result)[2]);
```

---

#### `int char_insertion_sort(char *arr, size_t arr_len, char **out)`

##### Description:
Sorts and array of characters from smallest to largest using insertion sort.
*Note*: Characters are compared directly using `>`.

##### Parameters: 
 - `arr`: The array of characters to sort.
 - `arr_len`: The length of arr.
 - `out`: A pointer to an array of characters used to pass back the return value. 
     - Note: `out` should point to `NULL` but should not be `NULL`. If `out` does not point to `NULL`, then it is up to the user to free what `out` points to prior to calling this function.

##### Return Value:
 - returns `0` on success and anything else on failure.

##### Example:
```c
int rc;
char *test = "BICEAFDGHJ";
size_t test_len = 10;
char **result = calloc(1, sizeof(char*));

printf("before sort: %s\n", test);
rc = char_insertion_sort(test, test_len, result);
if (rc != 0)
{
    printf("Failure in char_insertion_sort. Error: \"%s\"", sort_get_err());
    exit(1);
}
printf("after sort: %s\n", *result);
```

---

#### `int string_insertion_sort(char **arr, size_t arr_len, char ***out)`

##### Description: 
Sorts an array of strings using `strcmp` (from string.h) with insertion sort.

##### Parameters: 
 - `arr`: The array of strings to sort.
 - `arr_len`: The length of arr.
 - `out`: A pointer to an array of strings used to pass back the return value. 
     - Note: `out` should point to `NULL` but should not be `NULL`. If `out` does not point to `NULL`, then it is up to the user to free what `out` points to prior to calling this function.

##### Return Value:
 - returns `0` on success and anything else on failure.

##### Example:
```c
int rc;
char *test[] = { "cat", "ca", "hello", "World", "MrBitShift" };
size_t test_len = 5;
char ***result = calloc(1, sizeof(char**));
printf("before sort: %s, %s, %s, %s, %s\n", test[0], test[1], test[2],
    test[3], test[4]);
rc = string_insertion_sort(test, test_len, result);
if (rc != 0)
{
    printf("Failure in string_insertion_sort. Error: \"%s\"", sort_get_err());
    exit(1);
}
char **results = *result;
printf("after sort: %s, %s, %s, %s, %s\n", results[0], results[1],
    results[2], results[3], results[4]);
```

---

#### `int string_lex_insertion_sort(char **arr, size_t arr_len, char ***out)`

##### Description:
Sorts an array of strings using insertion sort into lexicographical order by converting them to lower case and then using `strcmp` to compare them.
*Note*: Case of strings is not affected in return value.

##### Parameters: 
 - `arr`: The array of strings to sort.
 - `arr_len`: The length of arr.
 - `out`: A pointer to an array of strings used to pass back the return value. 
     - Note: `out` should point to `NULL` but should not be `NULL`. If `out` does not point to null, then it is up to the user to free what `out` points to prior to calling this function.

##### Return Value:
 - returns `0` on success and anything else on failure.

##### Example:
```c
int rc;
char *test[] = { "cat", "ca", "hello", "World", "MrBitShift" };
size_t test_len = 5;
char ***result = calloc(1, sizeof(char**));
printf("before sort: %s, %s, %s, %s, %s\n", test[0], test[1], test[2],
    test[3], test[4]);
rc = string_lex_insertion_sort(test, test_len, result);
if (rc != 0)
{
    printf("Failure in string_lex_insertion_sort. Error: \"%s\"", sort_get_err());
    exit(1);
}
char **results = *result;
printf("after sort: %s, %s, %s, %s, %s\n", results[0], results[1],
    results[2], results[3], results[4]);
```
