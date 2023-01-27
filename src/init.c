#include "minishell.h"

/* Initialize the env used by our shell.
(inhenv : the inherited environment from the parent shell)*/
// void init_env(t_env *env, char **inhenv)
// {
// 	if (inhenv != NULL)
// 	{
// 		while (*inhenv != NULL)
// 		{
// 			env->name = ft_substr();
// 		}
// 	}
// }

void init_signals(void)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		;//err
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		;//err	
}

/* Initialize shell variables */
void	init_shvar(void)
{
	
}
