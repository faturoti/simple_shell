#include "main.h"

/**
 * shellby_env - Prints the current environment.
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1, Otherwise
 */

int shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int index;

	char nc = '\n';

	if (!environ)
	{
		return (-1);
	}

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;

	return (0);
}

/**
 * shellby_setenv - Changes or adds an environmental variable to the PATH.
 * @args: An array of arguments passed to the shell
 * @front: A double pointer to the beginning of args.
 *
 * Description: args[1] is the name of the new or existing PATH variable
 * 	args[2] is the value to set the new or changed variable to.
 * Return: If an error occurs - -1.
 */

int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL;
	char **new_environ;
	char *new_value;

	size_t size;
	int index;

	if (!args[0] || !args[1])
	{
		return (create_error(args, -1));
	}

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);

	if (!new_value)
	{
		return (create_error(args, -1));
	}

	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	env_var = _getenv(args[0]);

	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}

	for (size = 0; environ[size]; size++)
	{

	}

	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		return (create_error(args, -1));
	}

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = environ[index];
	}

	free(environ);
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;

	return (0);
}

