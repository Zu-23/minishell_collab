/* minishell.h -- The data and funtions used by the shell */
#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "parser.h"
# include "execute.h"
# include "../debug.h" ////???

/* Feature Test Macro Requirements */

/* Values that can be returned by execute_command (). */
#define EXEC_FAIL 1
#define EXEC_SUCC 0

/* The default value of the PATH variable. */
# define DPATH "/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:."

/* Default primary and secondary prompt strings. */
#define PPROMPT "\\s-\\v\\$ "
#define SPROMPT "> "

/* Possible values for the `vflag' field of a s_var. */
# define EXPORTED	0x01
# define ASSIGNED	0x02
# define SPECIAL	0x04
# define VISIBLE	0x08

/* Important environment variables. 
   Possible values for the `flag' in is_important function. */
# define IMPT_PWD		0x01
# define IMPT_PATH		0x02
# define IMPT_SHLVL		0x04
# define IMPT_OLDPWD	0x08
# define IMPT_ALL		0x0F

/* -------------------------------------------------------------------------- */
/*                                    Data                                    */
/* -------------------------------------------------------------------------- */

typedef struct s_var
{
	t_uint8 vflag;
	char *name;
	char *value;
}	t_var;

typedef struct s_varlst
{
	t_var			var;
	size_t			*len;
	struct s_varlst	*next;
	struct s_varlst	*prev;
}	t_varlst;

typedef struct s_env
{
	size_t	len;
	char	**env;
}	t_env;

typedef struct s_sh
{
	t_env		*env;
	t_varlst	*shvar;
	
	int 		ex_stat;
	int			eof_reached;
	// t_pipeline	*pipel;
}	t_sh;

extern t_sh g_sh;


/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

/*
** Basic Function :
*/

int			reader_loop (void);
void		exit_shell(int s);

/*
** initialization :
*/

void			init_env(char **inh_env);
void			init_signals(void);

/*
** Builtins :
*/

int cd_builtin(char *av[]);
int pwd_builtin(char *av[]);
int env_builtin(char *av[]);
int echo_builtin(char *av[]);
int exit_builtin(char *av[]);
int unset_builtin(char *av[]);
int export_builtin(char *av[]);

/*
** Variables manipulation :
*/

int			set_var(char *name, t_uint8 vflag);
t_varlst	*get_var(char *name);
void		del_var(char *name);

/*
** Errors handling :
*/


/*
** Utils :
*/
/* For variables */

t_uint8		is_important(char *var, t_uint8 flag);
t_bool		legal_var(char c, t_bool is_starter);
int			legal_identifier(char *id);
int			get_assign(char *name);

/* misc */
void qsort_var(t_var *vars, size_t len);

#endif
