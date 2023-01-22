#include "../shell_header.h"
#include <string.h>


char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

char	*get_token(char *str, char *tkn)
{
	tkn[1] = '\0';
	tkn[2] = '\0';
	if (*str == '>' || *str == '<')
	{
		tkn[0] = *str++;
		if (str[-1] == str[0])
			tkn[1] = *str++;
	}
	else if (*str == ' ' || *str == '\t')
	{
		tkn[0] = ' ';
		str = skip_spaces(str);
	}
	else
		tkn[0] = *str;
	return (str);
}
//hello\0
char	*ft_strtok(char *str, char *delim, int quoted)
{
	char		tkn[3];
	static char	*loc = NULL;

	if (!str)
		str = loc;
	if (!str || !str[0])
		return (NULL);
	while (str[i])
	{
		if (strchr(delim, str[i]))
		{
			loc = get_token(loc, tkn);
		}
	}
	loc = NULL;
	return (ft_strdup(str));
}