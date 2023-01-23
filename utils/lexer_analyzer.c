#include "../shell_header.h"
static int	err(char *str)
{
	printf("%s", str);
	return (1);
}

int	flag_val(int val, int flag, t_cmd *cmd)
{
	if (flag == 0)
		flag = val;
	else if (flag != val && cmd->next == NULL)
		return (-1);
	else if (flag == val)
		flag = 0;
	return (flag);
}
int	quote_syntax_err(t_cmd *cmd)
{
	static int	flag;

	if (!ft_strcmp(cmd->command, "\'"))
		flag = flag_val(1, flag, cmd);
	else if (!ft_strcmp(cmd->command, "\""))
		flag = flag_val(2, flag, cmd);

	if (flag == -1 || (cmd->next == NULL && flag))
	{
		flag = 0;
		return(err("unclosed quotes\n"));
	}
	return (0);
}

//delete later

int	pipe_wspace(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;

	tmp = cmd;
	tmp2 = cmd;
	if (tmp->prev->type == WSPACE || tmp2->next->type == WSPACE)
	{
		tmp = tmp->prev;
		tmp2 = tmp2->next;
		while (tmp && tmp->type == WSPACE)
			tmp = tmp->prev;
		while (tmp2 && tmp2->type == WSPACE)
			tmp2 = tmp2->next;
		if (!tmp || !tmp2)
			return (1);
		if (tmp->type != WORD || tmp2->type != WORD)
			return (1);
	}
	else if (cmd->prev->type != WORD || cmd->next->type != WORD)
		return (1);
	return (0);
}
//

int	pipe_syntax_err(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->command, "|"))
	{
		if (cmd->prev == NULL || cmd->next == NULL)
			return (err("parse error near | 1\n"));
		// else if (pipe_wspace(cmd))
		// 	return (err("parse error near | 2\n"));
	}
	return (0);
}

void doubly_lst_delete(t_cmd **cmd)
{
	if ((*cmd)->prev)
		(*cmd)->prev->next = (*cmd)->next;
	else if ((*cmd)->next)
		(*cmd)->next->prev = (*cmd)->prev;
	else
		*cmd = NULL;
	free(*cmd);
}

int	redirect_syntax_err(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->command, ">") || !ft_strcmp(cmd->command, ">>")
		|| !ft_strcmp(cmd->command, "<") || !ft_strcmp(cmd->command, "<<"))
		{
			if (cmd->next == NULL)
				return (err("parse error\n"));
			cmd = cmd->next;
			while (cmd && cmd->type == WSPACE)
				cmd = cmd->next;
			if (!cmd || (cmd->type != WORD))
				return (err("parse error\n"));
		}
	return (0);
}
t_cmd	*lst_first(t_cmd *cmd)
{
	while (cmd->prev);
		cmd = cmd->prev;
	return (cmd);
}

t_cmd	*lexer_analyzer(t_cmd *cmd)
{
	t_cmd	*tmp;
	//cmd points to the last node
	//we need to points to the first
	cmd = lst_first(cmd);//cmd points to head
	tmp = cmd;
	while (tmp)
	{
		if (tmp->state == GENERAL)
		{
			if (redirect_syntax_err(tmp) || pipe_syntax_err(tmp))
				return (NULL);
		}
		if (quote_syntax_err(tmp))
			return (NULL);
		tmp = tmp->next;
	}
	return (expander(cmd));
}
