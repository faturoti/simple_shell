#include "main.h"
int cant_open(char *file_path);
/**
 * cant_open - If the file doesn't exist or lacks proper permissions
 * @file_path: Path to the supposed file.
 *
 * Return - 127
 */
int cant_open(char *file_path)
{
	char *error, *hist_str;		
	/*Create memory loc for both*/
	int len;

	hist_str = _itoa(hist);		
	/*to convert integer to string*/
	
	if (!hist_str)
	{
		return (127);
	}

	len = _str_len(name) + _strlen(hist_str) + _strlen(file_path) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (127);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": CAn't Open ");
	_strcat(error, file_path);
	_strcat(error, "\n");

	free(hist_str);
	write(STDERR_FILENO, error, len);
	free(error);	

	return (127);
}

/**
 * proc_file_commands - Takes a file and attempts to run the commands stored
 * @file_path: Path to file
 * @exe_ret: Return value of the last executed comman
 *
 * Return: the last return value of last command.
 * 		-127 for file couldn't open
 * 		if malloc ails -1
 */

int proc_file_commands(char *file_path, int *exe_ret)
{
	ssize_t file, b_read, i;
	unsigned int line_size = 0;
	unsigned int old_size = 120;
	char *line, **args, **front;
	char buffer[120];

	int ret;
	hist = 0;

	file = (file_path, O_RDONLY);
	
	if (file == -1)
	{
		*exe_ret = cant_open(file_path);
		return (*exe_ret)
	}

	/*Line automatically has size of 120*/
	line = malloc(sizeof(char) * old_size);

	if (!line)
	{
		return (-1);
	}

	do
	{
		b_read = read(file, buffer, 119);	
		/*reads from file to buffer*/
		if (b_read == 0 && linesize == 0)
			return (*exe_ret);

		buffer[b_read] = '\0';	
		/*Null terminate the buffer*/
		line_size += b_read;
		line = _realloc(line, old_size, line_size);
		_strcat(line, buffer);
		old_size = line_size;		
	}
	while (b_read)
	{

	}
	for (i = 0; line[i] == '\n'; i++)
	{
		line[i] = ' ';
	}
	for (; i < line_size; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = ';';
			for (i += 1; i < line_size && line[i] == '\n'; i++)
			{
				line[i] = ' ';
			}
		}
	}
	variable_replacement(&line, exe_ret);
	handle_line(&line, line_size);

	args = _strtok(line, " ");
	free(line);
	if (!args)
	{
		return (0);
	}

	if (check_args(args) != 0)
	{
		*exe_ret = 2;
		free_args(args, args);
		return (*exe_ret);
	}
	front = args;
	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = call_args(args, front, exe_ret);
			args = &args[++i];
			i = 0;
		}
	}
	ret = call_args(args, front, exe_ret);

	free(front);
	return (ret);
}
