#include <stdio.h>
#include <stdlib.h>

void free_array(int **arr) {
    if (arr == NULL) return;

    // Free sub-arrays (NULL-terminated)
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr);  // Free the main array
}

int main() {
    int **array = malloc(3 * sizeof(int*));
    array[0] = malloc(2 * sizeof(int));
    array[1] = malloc(3 * sizeof(int));
    array[2] = NULL;  // NULL-terminated

    array[0][0] = 1; array[0][1] = 2;
    array[1][0] = 3; array[1][1] = 4; array[1][2] = 5;

    printf("Before free: array = %p\n", (void*)array);
    free_array(array);  // Free memory
    array = NULL;  // Caller must set to NULL!
    printf("After free: array = %p\n", (void*)array);

 
    int **null_array = NULL;
    printf("\nBefore free: null_array = %p\n", (void*)null_array);
    free_array(null_array);
    null_array = NULL;  /
    printf("After free: null_array = %p\n", (void*)null_array);

    return 0;
}
