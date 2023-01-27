#include "minishell.h"

t_sh	g_sh = {NULL, NULL, 0, 0};

#define NCMD 4

void add_cmd(t_cmd **cmds)
{
	t_cmd	*new;
	t_cmd	*iter = *cmds;
	new =  malloc(sizeof(t_cmd));
	new->next = NULL;
	if (iter == NULL)
		*cmds = new;
	else
	{
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
}

int main(int ac, char *av[], char *env[])
{
	int i = 0;
	// init_signals();
	char *cmd[][NCMD] = 
	{{"cat", "-e", NULL}, 
	{"grep",  "a", NULL},
	{"grep",  "b", NULL},
	{"cat",  "-e", NULL}};
	t_pipeline pipel;
	pipel.cmds = NULL;
	pipel.ncmd = NCMD;
	for (i = 0; i < NCMD; i++)
	{

		add_cmd(&pipel.cmds);
	}
	t_cmd	*cmds = pipel.cmds;
	for (i = 0; i < NCMD; i++)
	{
		cmds->argv = cmd[i];
		cmds = cmds->next;
	}
	execute(&pipel);
	exit_shell(g_sh.ex_stat);
	return (0);
}

/* Exit the shell with status S. */
void exit_shell(int s)
{
	exit(s);
}