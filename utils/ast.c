#include "../shell_header.h"
// /*grammar
// 	<cmdline>	::= <block>
// 		| <block> (";" | "&") <cmdline>

// <block>		::= <pipeline> {("&&" | "||") <pipeline>}

// <pipeline>	::= <command> {"|" <command>}

// <command>	::= <cmdlist>
// 		| "(" <cmdline> ")" <redir>	(* subshell *)

// <cmdlist>	::= <redir>+			(* at least one redirect - without WORDs *)
// 		| <redir> {<arg> <redir>}+	(* at least one WORD - zero or more <redir> in any place *)

// <redir>		::= {("<" | "<<" | ">" | ">>") <filename>}	(* a delimiter in case of heredoc *)

// <arg>		::= token WORD | token VAR | token GROUP

// <filename>	::= token WORD | token VAR | token GROUP
// */
// /// (aaa | (bbb | ccc))

// // arr[] aaa | bbb | ccc
static int	err(char *str)
{
	printf("%s", str);
	exit(1);
}
typedef struct s_word
{
	char	*word;
	int		flags;
}	t_word;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;
/* Structure describing a redirection. */
typedef struct s_redir
{
	int		op; //type value
	char	*opd;
}	t_redir;

/* What a command looks like. */
typedef struct s_cmdb
{
	char	**argv;
	t_list	*rdr_lst;
}	t_cmd_b;

int	get_lst_size(t_cmd *cmd)
{
	t_cmd 	*tmp;
	int		size;

	tmp = cmd;
	size = 0;
	while (tmp)
	{
		if (tmp->type == WORD)
			size++;
		tmp = tmp->next;
	}
	return (size);
}


char **get_argv(t_cmd *cmd)
{
	int		ls_size;
	int		i;
	char	**argv;
	t_cmd	*tmp;

	i = 0;
	tmp = cmd;
	ls_size = get_lst_size(cmd);
	argv = malloc(sizeof(char *) * (ls_size + 1));
	if (!argv)
		err("malloc faield\n");
	while(tmp)
	{
		if (tmp->type == WORD)
		{
			argv[i] = ft_strdup(tmp->command);
			i++;
		}
		tmp = tmp->next;
	}
	argv[i] = NULL;
	return (argv);
}

t_redir *create_redir_node(t_cmd *cmd)
{
	t_redir	*rdr_node;
	t_cmd	*tmp;

	tmp = cmd;
	rdr_node = malloc(sizeof(t_redir));
	if (!rdr_node)
		err("malloc failed\n");
	rdr_node->op = cmd->type;
	while (tmp)
	{
		if (tmp->type == REDIR_ARG)
			rdr_node->opd = ft_strdup(tmp->command);
		tmp = tmp->next;
	}
	return (rdr_node);
}
t_list	*create_rdr_lst_two(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_list	*n_lst;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->type >= GREAT && tmp->type <= DGREAT)
		{
			n_lst = malloc(sizeof(t_list));
			return (n_lst);
		}
	}
	return (NULL);
}

t_list *create_rdr_lst(t_cmd *cmd)
{
	t_list	*rdr_lst_head;
	t_list	*rdr_tmp;
	t_cmd	*tmp;

	rdr_lst_head = malloc(sizeof(t_list));
	rdr_tmp = rdr_lst_head;
	tmp = cmd;
	while (tmp)
	{
		if (tmp->type >= GREAT && tmp->type <= DGREAT)
		{
			rdr_tmp->content =(void*) create_redir_node(tmp);
			rdr_tmp->next = create_rdr_lst_two(tmp->next);
			rdr_tmp = rdr_tmp->next;
		}
		tmp = tmp->next;
	}
	return (rdr_lst_head);
}

t_cmd_b create_cmd(t_cmd *cmd)
{
	t_cmd_b 	p_c;

	p_c.argv = get_argv(cmd);
	p_c.rdr_lst = create_rdr_lst(cmd);
	return (p_c);
}

t_cmd *expander(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		if ((!ft_strcmp(tmp->command, " ") && tmp->state == GENERAL))
		{
			if (!tmp->prev && tmp->next)
			{
				cmd = tmp->next;
				tmp->next->prev = NULL;
			}
			else if (!tmp->next && tmp->prev)
				tmp->prev->next = NULL;
			else if (tmp->prev && tmp->next)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			free(tmp->command);
			free(tmp);
			tmp = cmd;
		}
		else
			tmp = tmp->next;
	}
	create_cmd(cmd);
	// create_new_lst(cmd);
	// tmp = cmd;
	// while (tmp)
	// {
	// 	printf("command: %s --- state: %d\n", tmp->command, tmp->state);
	// 	tmp = tmp->next;
	// }
	return (cmd);
}

// t_node *parse_pipe(t_cmd *cmd, t_node *tree)
// {
// 	t_node	*pip_red;

// 	pip_red = malloc(sizeof(t_node));
// 	if (cmd->prev->type == PIPE)
// 		pip_red->node_type = PIPE;
// 	else if (cmd->prev->type >= REDIR_IN && cmd->prev->type <= REDIR_DOC)
// 		pip_red->node_type = REDIR;
// 	pip_red->node_data.pipe.left = tree;
// 	pip_red->node_data.pipe.right = asyntax(cmd);
// 	return (pip_red);
// }

// void	parse_args(t_cmd *cmd, t_node **tree)
// {
// 	int		size;
// 	t_cmd 	*tmp;

// 	size = 0;
// 	tmp = cmd;
// 	while (tmp->next && tmp->next->type == WORD)
// 	{
// 		tmp = tmp->next;
// 		size++;
// 	}
// 	(*tree)->node_data.cmarg.arg = malloc(sizeof(char **) * (size + 1));
// 	if (!(*tree)->node_data.cmarg.arg)
// 		return ;
// 	tmp = cmd;
// 	size = 0;
// 	while (tmp->next && tmp->next->type == WORD)
// 	{
// 		tmp = tmp->next;
// 		(*tree)->node_data.cmarg.arg[size++] = tmp->command;
// 	}
// 	(*tree)->node_data.cmarg.arg[size] = NULL;
// }

// void parse_command(t_cmd *cmd, t_node **tree)//function that creates t_node node for command
// {
// 	if ((!cmd->prev || cmd->prev->type != WORD) && (cmd->type == WORD))
// 	{
// 		*tree = malloc(sizeof(t_node));
// 		if (!*tree)
// 			return ;
// 		(*tree)->node_type = COMMAND;
// 		(*tree)->node_data.cmarg.command = cmd->command;
// 		parse_args(cmd, tree);
// 	}
// 	else if (!cmd->prev)
// 		*tree = NULL;
// }
// // void	visit(t_node *tree)
// // {
// // 	if (tree->node_type != PIPE)
// // 		printf("command: %s\n",tree->node_data.cmarg.command);
// // 	else if (tree->node_type == PIPE)
// // 	{
// // 		printf("pipe |\n");
// // 		visit(tree->node_data.pipe.left);
// // 		visit(tree->node_data.pipe.right);
// // 	}
// // }

// t_node *asyntax(t_cmd *cmd)
// {
// 	t_cmd	*tmp;
// 	t_node	*tree;

// 	tmp = cmd;
// 	while (tmp)
// 	{
// 		parse_command(tmp, &tree);
// 		if (tmp->type == PIPE || (tmp->type >= REDIR_OUT && tmp->type <= REDIR_DOC))
// 		{
// 			tmp = tmp->next;
// 			tree = parse_pipe(tmp, tree);
// 			break ;
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (tree);
// }