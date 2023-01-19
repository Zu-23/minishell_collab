#include "../shell_header.h"

void	handler(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	cleaner(t_env_struct *env)
{
	int	i;

	i = 0;
	rl_clear_history();
	free(env);

}