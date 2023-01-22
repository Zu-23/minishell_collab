#include "shell_header.h"


t_cmd	*lexer(char *token, t_cmd *cmd)
{

	if (cmd == NULL)
		cmd = lst_init(cmd, token);
	else
		cmd = lst_add(cmd, token);
	return (cmd);
}

int	check_input(char *input)
{
	int	i;

	i = 0;

	if (!input[0] || ft_isspace(input))
		return (1);
	while (input[i] == '\"' || input[i] == '\'' || input[i] == ' ')
		i++;
	if (input[i] == '\0')
		return (1);
	return (0);

}


int main(int ac, char **av, char **env)
{
	char		*input;
	char		*token;
	t_cmd		*cmd;

	int tkn = 0;

	cmd = NULL;
	while (1)
	{
		input = readline("$>");
		if (!input)
			break ;
		if (check_input(input))
			continue ;
		if (ft_strlen(input) > 0)
			add_history(input);
		token = ft_strtok(input, g_tkns[tkn]);
		while (token)
		{
			cmd = lexer(token, cmd); // return the last added token
			tkn = (cmd->type == DQUOTE) + (cmd->type == SQUOTE) * 2;
			token = ft_strtok(NULL, g_tkns[tkn]);
		}
		cmd = lexer_analyzer(cmd);
		cmd = lst_delete(cmd);
	}
}

// " ' | 

// " |

//"hello wolrd" | > hello