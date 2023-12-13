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
	char *error, *hist_str;		//Create memory loc for both
	int len;

	hist_str = _itoa(hist);		//to convert integer to string
	
	if (!hist_str)
	{
		return(127);
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

	//Line automatically has size of 120
	line = malloc(sizeof(char) * old_size);

	if(!line)
	{
		return (-1);
	}

	do
	{
		b_read = read(file, buffer, 119);	//reads from file to buffer
		if (b_read == 0 && linesize == 0)
			return (*exe_ret);

		buffer[b_read] = '\0';	//Null terminate the buffer
		
	}
}
