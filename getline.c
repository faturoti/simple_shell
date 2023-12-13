#include "main.h"

/**
 * _realloc -  Reallocates a memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: he size in bytes for the new memory block
 *
 * Return: if new_size == old_size - ptr
 * 		if new_size == 0 && ptr is not NULL return NULL
 * 		Otherwise - a pointer to the reallocated memory block.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;	//Pointer to new memory location
	char *filler, *ptr_copy;	//Duplicate pointer for mem and ptr
	unsigned int index;

	if (new_size == old_size)	//Nothing to do
	{
		return(ptr);
	}

	if (new_size == 0 && ptr != NULL)	//Just free PTR and leave
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)	//Just allocate the new size specified by new_size
	{
		mem = malloc(new_size);
		if (mem == NULL)
		{
			return (NULL);
		}

		return (mem);
	}

	//Otherwise do this below
	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);	//allocate space by factor of new_size

	if (mem == NULL)	//If the allocation fails, return NULL
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;	//create duplicate for mem to fill memory

	for (index = 0; index < old_size && index < new_size; index++)
	{
		filler[index] = *ptr_copy++;
	}

	free(ptr);

	return (mem);
}
