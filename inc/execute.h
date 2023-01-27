#ifndef EXEC_CMD_H
# define EXEC_CMD_H

/* Possible values for the `op' field of a s_redir. */
# define R_INPUT 0
# define R_OUTPUT 1
# define R_APPOUTP 2
# define R_HEREDOC 3

int	execute(t_pipeline *pl);

#endif
