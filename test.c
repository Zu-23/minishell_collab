#include<stdio.h>
#include<unistd.h>

int	n_opt_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-' && str[i+1] == 'n')
	{
		while (str[++i] == 'n');
		if (str[i] != '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	ft_echo(char **argv)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = "\n";
	while (argv[i])
	{
		if (n_opt_check(argv[i]))
			new_line = "";
		else
		{
			printf("%s",argv[i]);
			if (argv[i + 1])
				printf(" ");
		}
        i++;
	}
    printf("%s",new_line);
}
