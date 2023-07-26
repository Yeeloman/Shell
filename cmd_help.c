#include "main.h"

/**
 *getCmdArgs - gets command and its args
 *@data: all relevent data
 *@path: the path to the executable command
*/


void getCmdArgs(shell_data *data, char *path)
{
	char *command = _strdup(_strtok(path, " "));

	data->cmd = (char *)malloc(_strlen(command) + 1);
	_strcpy(data->cmd, command);
	data->args[0] = (char *)malloc(_strlen(command) + 1);
	_strcpy(data->args[0], command);
	free(command);
}

/**
 *errorMaker - makes the error messege
 *@data: shell's data
 *@str1: part of the messege
 *@str2: part of the messege
 *Return: pointer to the error messege
*/

char *errorMaker(shell_data *data, char *str1, char *str2)
{
	char *errorMsg = NULL;

	errorMsg = malloc(sizeof(char) * 64);
	if (errorMsg == NULL)
		return (NULL);

	_strcpy(errorMsg, str1);
	_strcat(errorMsg, " : ");
	_strcat(errorMsg, data->input);
	_strcat(errorMsg, str2);

	return (errorMsg);
}


/**
 *isPath - handles the path
 *@data: shell's data
 *Return: pointer to the path
*/

char *isPath(void)
{
	char *path_copy;
	char *path = _getenv("PATH");

	if (!path)
		path_copy = strdup("/usr/local/bin:/usr/bin:/bin");
	else if ((_strcmp(path, "") == 0))
		path_copy = _strdup("");
	else
		path_copy = _strdup(path);
	return (path_copy);
}

/**
 *printError - prints the error
 *@data: shell's data
 *@str1: part of the messege
 *@str2: part of the messege
 *@status: the status of the shell
*/

void printError(shell_data *data, char *str1, char *str2, int status)
{
	char *errormsg;

	errormsg = errorMaker(data, str1, str2);
	write(STDERR_FILENO, errormsg, _strlen(errormsg));
	free(errormsg);
	data->status = status;
}
