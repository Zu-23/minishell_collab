//#include "../shell_header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);


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
		tkn[0] = *str++;
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	char		tkn[3];
	int			i;
	static char	*loc;

	if (!str && !loc[0])
		return (NULL);
	else if (!str)
		str = loc;
	else
		loc = str;
	i = 0;
	if (strchr(delim, str[i]))
		loc = get_token(&str[i], tkn);
	else
		while (strchr(delim, str[i]) == NULL)
			i++;
	if (i == 0)
		return (ft_strdup(tkn));
	loc += i;
	return (ft_substr(str, 0, i));
}

