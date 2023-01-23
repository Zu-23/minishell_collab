#include "shell_header.h"


t_cmd	*tokenizer(char *token, t_cmd *cmd)
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

	while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
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
	int 		tkn;

	cmd = NULL;
	tkn = 0;
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
			printf("token = %s\n", token);
			cmd = tokenizer(token, cmd); // return the last added token
			tkn = (cmd->type == DQUOTE) + (cmd->type == SQUOTE) * 2;
			token = ft_strtok(NULL, g_tkns[tkn]);
		}
		cmd = lexer_analyzer(cmd);
		cmd = lst_delete(cmd);
	}
}
