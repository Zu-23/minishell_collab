#include "../shell_header.h"

void	search_env(t_cmd *cmd, t_env_struct *env)
{
	int	i;

	i = -1;
	while (env[++i].var)
	{
		if (!ft_strcmp(cmd->command, env[i].var))
		{
			free(cmd->command);
			cmd->command = ft_strdup(env[i].value);
			return ;
		}
	}
	doubly_lst_delete(cmd);
}

int    print_expansion(t_cmd *cmd, t_env_struct *env)
{
    if ((cmd->state == GENERAL || cmd->state == IN_DQ)
        && (cmd->next->type == WORD) && (cmd->next->state == GENERAL
        || cmd->next->state == IN_DQ))
    {
        search_env(cmd->next, env);
        doubly_lst_delete(cmd);
        return (1);
    }
    return (0);
}

int    dont_print_expansion(t_cmd *cmd)
{
    if ((cmd->state == GENERAL || cmd->state == IN_Q)
        && (cmd->next->type == WORD && (cmd->next->state == IN_Q
        || cmd->next->state == IN_DQ)))
        return (1);
    else if (cmd->state == GENERAL && (cmd->next->type == WORD
            && cmd->next->state == IN_Q))
        {
            doubly_lst_delete(cmd);
            return (1);
        }
    return (0);
}

void	expansion(t_cmd *cmd, t_env_struct *env)//comes after removing quotes
{
	t_cmd	*tmp;

	tmp = cmd;
	while(tmp)
	{
		if (!ft_strcmp(cmd->command, "$") && cmd->next)
		{
           if (print_expansion(cmd, env));
           else
			    dont_print_expansion(cmd);
		}
        tmp = cmd;
        tmp = tmp->next;
	}
}