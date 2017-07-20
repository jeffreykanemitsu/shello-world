#include "shell.h"

int find_builtins(char *str)
{
	int i;

	builtins_t builtins[] = {
		{"env", _env},
		{"exit", __exit},
		{NULL, NULL}
	};

	i = 0;
	while (builtins[i].cmd != NULL)
	{
		if (_strcmp(str, builtins[i].cmd) == 0)
			{
				builtins[i].f(str);
				return (0);
			}
			i++;
	}
	return (-1);
}

int _env(char *envp[])
{
	int x, y;

	for (x = 0; envp[x] != '\0'; x++)
	{
		for (y = 0; envp[x][y] != '\0'; y++)
		{
			write(STDOUT_FILENO, &envp[x][y], 3);
		}
		write (STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
	

int __exit(void)
{
	exit(98);
}
