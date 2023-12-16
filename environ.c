#include "main.h"

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: double pointer to the new environs or NULL
 */

char **_cpyenv(void)
{
	char **new_environ;	
	/*pointer to a copy of environ*/
	size_t size;		
	/*size tracker*/
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);
	
	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(_strlen(environ[index]) + 1);  
		/*allocate space for string to be copied*/
		
		if (!new_environ[index])	
			/
			/*If no more space to allocate*/
		{
			for (index--; index >= 0; index--)
			{
				/*THen rocover space and return NULL*/
				free(new_environ[index]);
			}
			free(new_environ);
			return (NULL);
		}
		_strcpy(environ[index], new_environ[index]);	
		/*Makes full copies of each index*/
	}

	new_environ[index] = NULL;	
	/*Ensures it is NULL terminated*/
	
	return (new_environ);		/*Return pointer to new_environ*/
}
