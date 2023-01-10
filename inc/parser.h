#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include <stdio.h>
# include "../debug.h" ////???

/* Possible values for the `flags' field of a s_word. */
#define W_HASDOLLAR	(1 << 0)	/* Dollar sign present. */
#define W_QUOTED	(1 << 1)	/* Some form of quote character is present. */
#define W_NOTILDE	(1 << 12)	/* Don't perform tilde expansion on this word */

/* A structure which represents a WORD. */
typedef struct s_word
{
	char	*word;
	int		flags;
}	t_word;

/* Structure describing a redirection. */
typedef struct s_redir
{
	t_uint8_t	op;
	t_word		*opd;
}	t_redir;

/* What a command looks like. */
typedef struct s_cmd
{
	char	**argv;
	t_list	*rdr_lst;
}	t_cmd;

/* What a pipeline looks like. */
typedef struct s_pipeline
{
	t_cmd				cmd;
	struct s_pipeline	*next;
}	t_pipeline;

#endif
