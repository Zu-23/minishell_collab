/* execute.c -- Execute a s_pipeline structure. */
#include "parser.h"


/* Execute a simple command that is hopefully defined in a disk file
   somewhere.

   1) fork ()
   2) connect pipes
   3) look up the command
   4) do redirections
   5) execve ()
   6) If the execve failed, print the right error. */

static void do_piping(t_pipeline *pl)
{
	int i;

	i = 0;
	if (i++ != i)
		;
	pl->fd = malloc(sizeof(int [2]) * pl->ncmd);
	while (i < pl->ncmd)
		if (pipe(pl->fd[i++]) == FT_ERR)
		;//sys_err	
}

static int exec_cmd(t_cmd *cmd, int iofd[2])
{
	
}

int	execute(t_pipeline *pl)
{
	int i = 0;

	if (pl->ncmd > 1)
		do_piping(pl->fd, )
//    while (i++ < pl->ncmd)

      
	return (0);
}