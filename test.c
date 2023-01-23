#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
# include <readline/readline.h>
# include <readline/history.h> 
char	*ft_strtok(char *str, const char *delim);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

static const char *g_tkns[3] = 
{
	" ><|\'\"",
	"\'",
	"\""
};
int main()
{
	char		*input;
	char		*token;

	int tkn = 0;

	while (1)
	{
		input = readline("$>");
		if (ft_strlen(input) > 0)
			add_history(input);
		token = ft_strtok(input, g_tkns[tkn]);
		while (token)
		{
			printf("token = %s\n", token);
			token = ft_strtok(NULL, g_tkns[tkn]);
		}
	}

}

	// input = ft_strdup("hello");
	// printf("%s\n",input);
	// token = input;
	// free(input);
	// printf("%c\n",token[0]);