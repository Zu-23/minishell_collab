#include "../shell_header.h"

int	pwd(char **argv)
{
    char	path[PATH_MAX];

    if (argv[0] == '-' && argv[1] != '\0')
        printf("pwd: inavlid option\n");
    else
	{
		getcwd(path, PATH_MAX);
		printf("%s\n",path);
	}
	free(path);
}

