/* variables.c -- Functions for hacking shell variables. */
#include "minishell.h"

static void bind_var(t_var *var, char *value, t_bool append)
{
	void *old_value;

	old_value =  (void *)var->value;
	if (append)
		var->value = ft_strjoin(var->value, value); //err
	else
		var->value = ft_strdup(value);
	free(old_value);
}

static t_varlst	*add_var(char *name, char *value, t_uint8 vflag)
{
	t_varlst *new_node;

	new_node = malloc(sizeof (t_varlst)); // err
	new_node->var.name = ft_strdup(name); // err
	if (vflag & ASSIGNED)
		new_node->var.value = ft_strdup(value); // err
	else
		new_node->var.value = NULL;
	new_node->prev = NULL;
	new_node->next = g_sh.shvar;
	if (g_sh.shvar != NULL)
	{
		g_sh.shvar->prev = new_node;
		new_node->len = g_sh.shvar->len;
	}
	else
		new_node->len = ft_calloc(1, sizeof(size_t)); // err
	g_sh.shvar = new_node;
	++*g_sh.shvar->len;
	return (new_node);
}

t_varlst *get_var(char *name)
{
	t_varlst *vars;

	vars = g_sh.shvar;
	while (vars != NULL)
	{
		if (ft_strcmp(vars->var.name, name) == 0)
			return (vars);
		vars = vars->next;
	}
	return (NULL);
}

int set_var(char *name, t_uint8 vflag)
{
	int	assign;
	t_bool	append;
	t_varlst *node;

	append = FT_FALSE;
	name = ft_strdup(name); // err
	assign = get_assign(name);
	if (assign > 0)
	{
		vflag |= ASSIGNED;
		name[assign] = '\0';
		append = name[assign - 1] == '+';
		name[assign - append] = '\0';
	}
	// err inv id
	if (legal_identifier(name) == 0)
		return (fprintf(stderr, "Invalid identifier\n"));
	node = get_var(name);
	if (node == NULL)
		node = add_var(name, &name[assign + 1], vflag);
	else if (assign > 0)
		bind_var(&node->var, &name[assign + 1], append);
	node->var.vflag |= vflag;
	free(name);
	return (EXEC_SUCC);
}

void del_var(char *name)
{
	t_varlst *node;

	node = get_var(name);
	if (node == NULL)
		return ;
	free(node->var.name);
	free(node->var.value);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == g_sh.shvar)
		g_sh.shvar = node->next;
	free(node);
}
