#include "minishell.h"

/* Read commands until exit condition. */
int reader_loop(void)
{
	char	*cmdline;
	// t_pipeline *pipel;
	const char *prompt = NULL;

	if (isatty(0))
		prompt = PPROMPT;
	while (g_sh.eof_reached == 0)
		cmdline = readline(prompt);
	// pipel = parser(cmdline);
}