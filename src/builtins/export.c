#include "minishell.h"

static void print_var(t_var *var_arr)
{
	int		i;
	char	*s[3];

	i = -1;
	while (++i < *g_sh.shvar->len)
	{
		s[0] = var_arr[i].name;
		s[1] = "";
		s[2] = "";
		if (var_arr[i].vflag & ASSIGNED)
		{
			s[1] = "=\"";
			s[2] = var_arr[i].value;
		}
		printf("declare -x %s%s%s%c\n", s[0], s[1], s[2], s[1][1]);
	}

}

static void show_var(void)
{
	int			i;
	t_varlst	*vars;
	t_var		*var_arr;

	if (g_sh.shvar == NULL)
		return ;
	i = 0;
	vars = g_sh.shvar;
	var_arr = malloc(sizeof(t_var) * *g_sh.shvar->len);
	while (vars)
	{
		if (vars->var.vflag & EXPORTED)
			var_arr[i++] = vars->var;
		vars = vars->next;
	}
	qsort_var(var_arr, *g_sh.shvar->len);
	print_var(var_arr);
}

/*
** BUILTIN export
** FUNCTION export_builtin
** SHORT_DOC export [name[=value] ...]
** Set export attribute for shell variables.
*/
int	export_builtin(char *av[])
{
	if (av[1] == NULL)
		show_var();
	else
		while (*(av++ + 1))
			set_var(*av, EXPORTED);
	return (FT_SUCC);
}