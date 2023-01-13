#include "../shell_header.h"

static int	err(char *str)
{
	printf("%s\n",str);
	return (-1);
}

int	ft_cd(char **argv)
{
	char path[PATH_MAX];

	if (argv[1] == NULL)
	{
		if (chdir(getenv("HOME") == -1));
			err("cd: HOME not set");
		return (1);
	}
	else
	{ 
		if (chdir(argv[1]) == -1)
		{
			printf(" %s: no such directory\n", argv[1]);
            return (-1);
		}
		else
		{
			if ((!ft_strcmp(argv[1], ".") || !ft_strcmp(argv[1], "..")) && !getcwd(path, PATH_MAX))
				return (err("cd: error retrieving current directory:\
				getcwd: cannot access parent directories: No such file or directory"));
		}
	}
	return (0);
}