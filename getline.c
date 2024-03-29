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
	void *mem;	
	/*Pointer to new memory location*/
	char *filler;
	char *ptr_copy;	
	/*Duplicate pointer for mem and ptr*/
	unsigned int index;

	if (new_size == old_size)	
		/*Nothing to do*/
	{
		return(ptr);
	}

	if (new_size == 0 && ptr != NULL)	
		/*Just free PTR and leave*/
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)	
	/*Just allocate the new size specified by new_size*/
	{
		mem = malloc(new_size);
		if (mem == NULL)
		{
			return (NULL);
		}

		return (mem);
	}

	/*Otherwise do this below*/
	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);	
	/*allocate space by factor of new_size*/

	if (mem == NULL)	
	/*If the allocation fails, return NULL*/
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;	
	/*create duplicate for mem to fill memory*/

	for (index = 0; index < old_size && index < new_size; index++)
	{
		filler[index] = *ptr_copy++;
	}

	free(ptr);

	return (mem);
}

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
		{
			*n = b;
		}
		else
		{
			*n = 120;
		}
		*lineptr = buffer;
	}
	else if (*n > b)
	{
		if (b > 120)
		{
			*n = b;
		}
		else
		{
			*n = 120;
		}
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}

}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x';
       	char *buffer;
	int r;

	if (input == 0)
	{
		fflush(stream);
	}
	else
	{
		return (-1);
	}

	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
	{
		return (-1);
	}

	while (c != "\n")
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free (buffer);
			retun (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
		{
			buffer = _realloc(buffer, input, input + 1);
		}
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);
	ret = input;

	if (r != 0)
	{
		input = 0;
	}

	return (ret);	

}
