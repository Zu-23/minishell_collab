#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

/* Possible values for the `flags' field of a s_word. */
#define W_HASDOLLAR	(1 << 0)	/* Dollar sign present. */
#define W_QUOTED	(1 << 1)	/* Some form of quote character is present. */
#define W_NOTILDE	(1 << 12)	/* Don't perform tilde expansion on this word */

/* A structure which represents a <word_list>. */
typedef struct s_word_lst
{
	int		flags;
	char	*word;
	struct s_word_lst *next;
}	t_word_lst;

/* A linked list describing a redirection_list . */
typedef struct s_redir
{
	t_uint8			op;
	t_word_lst		opd;
	struct s_redir	*next;
}	t_redir;


/* A linked list of commands. */
typedef struct s_cmd
{
	char			**argv;
	t_redir			*rdr_lst;
	struct s_cmd	*next;
}	t_cmd;

/* What a pipeline looks like. */
typedef struct s_pipeline
{
	t_uint		ncmd;
	t_uint		hdoc;
	int			(*fd)[2];
	t_cmd	*cmds;
}	t_pipeline;

#endif
