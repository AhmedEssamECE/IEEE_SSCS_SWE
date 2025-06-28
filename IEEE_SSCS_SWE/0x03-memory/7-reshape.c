#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *_reshape(void *ptr, size_t old_size, size_t new_size)
{

    // Create your own version of the realloc function.
    //   ● Prototype : void *_reshape(void *ptr, size_t old_size, size_t new_size);
    // ● If ptr is NULL, behave like malloc.
    // ● If new_size is 0, free the memory and return NULL.
    //  ●  Otherwise, allocate new memory, copy the old contents, free the old memory, and return the new pointer.

    if (ptr == NULL)
    {
        return malloc(new_size);
    }
    else if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }
    else
    {
        void *new_ptr = malloc(new_size);
        if (new_ptr == NULL)
        {
            return NULL;
        }
        else
        {
            memcpy(new_ptr, ptr, old_size);
            free(ptr);
            return new_ptr;
        }
    }
}