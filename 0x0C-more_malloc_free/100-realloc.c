
Skip to content
Pull requests
Issues
Marketplace
Explore
@Abdiye
wawababa /
alx-low_level_programming
Public

Code
Issues
Pull requests
Actions
Projects
Wiki
Security

    Insights

alx-low_level_programming/0x0C-more_malloc_free/100-realloc.c
@wawababa
wawababa commit
Latest commit e0773aa 7 hours ago
History
1 contributor
executable file 41 lines (39 sloc) 896 Bytes
#include <stdlib.h>
#include "main.h"
/**
  * _realloc - reallocates a memory block using malloc and free.
  * @ptr: pointer to the memory previously allocated with a
  * call to ``` malloc : malloc(old_size) ```.
  * @old_size: size in bytes allocated for ptr.
  * @new_size: size in bytes of new memory block.
  *
  * Return: pointer to new mem block, NULL or ptr.
  */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if ((new_size == 0) && (ptr != NULL))
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		if (nptr == NULL)
			return (NULL);
	}
	if (new_size > old_size && (ptr != NULL))
	{
		nptr = malloc(new_size);
		if (nptr == NULL)
			return (nptr);
		for (i = 0; i < old_size; i++)
			nptr[i] = *((char *)ptr + 1);
		free(ptr);
	}

	return (nptr);
}
