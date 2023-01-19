#include "shell_header.h"


t_cmd	*lexer(char *token, t_cmd *cmd)
{

	if (cmd == NULL)
		cmd = lst_init(cmd, token);
	else
		cmd = lst_add(cmd, token);
	return (cmd);
}

t_env_struct *get_env(char **env)
{
	int i;
	int	j;
    char ***splitted_2d_env;
    t_env_struct *env_var;

	i = 0;
	j = 0;
    while (env[i])
        i++;
    env_var = malloc(sizeof(t_env_struct) * i);
    splitted_2d_env = malloc(sizeof(char **) * (i + 1));
    i = -1;
    while (env[i])
        splitted_2d_env[i] = ft_split(env[i], '=');
    splitted_2d_env[i] = NULL;
    while (splitted_2d_env[j])
    {
		i = 0;
        while (splitted_2d_env[j][i])
        {
            env_var[j].var = ft_strdup(splitted_2d_env[j][i++]);
            env_var[j].value = ft_strdup(splitted_2d_env[j][i++]);
        }
        j++;
    }
	free(splitted_2d_env);
	return (env_var);
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
	char		**env_stock;

	cmd = NULL;
	(void)ac;
	(void)av;
	env_stock = get_env(env);
	while (1)
	{
		input = readline("$>");
		if (!input)
			break ;
		if (check_input(input))
			continue ;
		if (ft_strlen(input) > 0)
			add_history(input);
		token = ft_strtok(input, " \'\"$><&\\|");
		while (token)
		{
			cmd = lexer(token, cmd);
			free(token);
			token = ft_strtok(NULL, " \'\"$><&\\|");
		}
		cmd = lexer_analyzer(cmd);
		cmd = lst_delete(cmd);
	}
	cleaner(env_stock);
}

