#ifndef SHELL_HEADER_H
# define SHELL_HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h> 
# include <signal.h>

static const char *g_tkns[3] = 
{
	" ><|\'\"",
	"\'",
	"\""
};

typedef enum types
{
	PIPE = (1 << 0),
	DLESS = (1 << 1),
	DGREAT = (1 << 2),
	LESS = (1 << 3),
	GREAT = (1 << 4),
	WSPACE = (1 << 5),
	DQUOTE = (1 << 6),
	SQUOTE = (1 << 7),
	HASDOLLAR = (1 << 8),
	WORD = (1 << 9),
	STRING = (WORD | DQUOTE | SQUOTE | HASDOLLAR),
	REDIR = (DLESS | DGREAT | LESS |  GREAT)
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

// /* A structure which represents a <word_list>. */
// typedef struct s_word_lst
// {
// 	int		flags;
// 	char	*word;
// 	struct s_word_lst *next;
// }	t_word_lst;

// /* A linked list describing a redirection_list . */
// typedef struct s_redir
// {
// 	t_uint8			op;
// 	t_word_lst		opd;
// 	struct s_redir	*next;
// }	t_redir;

// /* A linked list of commands. */
// typedef struct s_cmd
// {
// 	int				flags;
// 	t_uint			hdoc;
// 	pid_t			pid;
// 	t_word_lst		*words;
// 	t_redir			*rdr_lst;
// 	struct s_cmd	*next;
// }	t_cmd;

// /* The structure used internally to represent pipeline */
// typedef struct s_pipeline
// {
// 	t_uint	ncmd;
// 	int		prev;
// 	int		fd[2];
// 	pid_t	*lastpid;
// 	t_cmd	*cmd;
// }	t_pipeline;

void	expansion(t_cmd *cmd, t_env_struct *env);
void	ft_perror(char *str);
int     ft_isspace(char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strtok(char *str, char *delim);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	doubly_lst_delete(t_cmd *cmd);
t_cmd	*lst_add(t_cmd *cmd, char *token);
t_cmd 	*lst_last(t_cmd *cmd);
t_cmd	*lst_init(t_cmd *cmd, char *token);
t_cmd	*lst_delete(t_cmd *cmd);
t_cmd	*tokenizer(char *token, t_cmd *cmd);
t_cmd	*lexer_analyzer(t_cmd *cmd);
t_cmd 	*expander(t_cmd *cmd);
t_node 	*asyntax(t_cmd *cmd);
t_states check_state(char *str);

#endif
