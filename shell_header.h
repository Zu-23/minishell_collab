#ifndef SHELL_HEADER_H
# define SHELL_HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h> 
# include <signal.h>
typedef enum types
{
	EOF = (0 << 0),
	NEWLINE = (1 << 0),
	PIPE = (1 << 1),
	DLESS = (1 << 2),
	DGREAT = (1 << 3),
	LESS = (1 << 4),
	GREAT = (1 << 5),
	DQUOTE = (1 << 6),
	SQUOTE = (1 << 7),
	WSPACE = (1 << 8),
	HASDOLLAR = (1 << 9),
	WORD = (1 << 10),
	STRING = (WORD | DQUOTE | SQOUTE | HASDOLLAR),
}	t_types;

typedef enum states
{
	IN_Q = 1,
	IN_DQ = 2,
	GENERAL = 3
}t_states;

// test area
typedef struct node t_node;
typedef struct cmarg
{
  char *command;
  char **arg;
}t_cmarg;

typedef struct pipe_redir
{
	t_node	*right;
	t_node	*left;
}t_pip_red;

typedef struct environment
{
	char *var;
	char *value;
}t_env_struct;

typedef union ast_val
{
   t_cmarg		cmarg;
   t_pip_red	pipe;
}t_ast_val;

struct node
{
	t_types		node_type;
	t_ast_val 	node_data;
};

//end of test area

typedef struct cmd
{
	char 			*command;
	t_types			type;
	t_states		state;
	struct cmd		*next;
	struct cmd		*prev;
}t_cmd;

void	expansion(t_cmd *cmd, t_env_struct *env);
void	ft_perror(char *str);
int     ft_isspace(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strtok( char *str, char *delim);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
t_cmd	*doubly_lst_delete(t_cmd *cmd);
t_cmd	*lst_add(t_cmd *cmd, char *token);
t_cmd 	*lst_last(t_cmd *cmd);
t_cmd	*lst_init(t_cmd *cmd, char *token);
t_cmd	*lst_delete(t_cmd *cmd);
t_cmd	*lexer(char *token, t_cmd *cmd);
t_cmd	*lexer_analyzer(t_cmd *cmd);
t_cmd 	*expander(t_cmd *cmd);
t_node 	*asyntax(t_cmd *cmd);
t_states check_state(char *str);

#endif
