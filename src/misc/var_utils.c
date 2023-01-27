#include "minishell.h"

/* Define exactly what a legal shell identifier consists of. */
inline t_bool legal_var(char c, t_bool is_starter)
{
	return ((is_starter && ft_isalpha(c))
	|| (!is_starter && ft_isalnum(c)) || c == '_');
}

/* Returns non-zero if NAME is an assignment statement.  The returned value
   is the index of the `=' sign.  A compound assignment is checked
   and require an array subscript before the `=' to denote an assignment
   statement. */
int	get_assign(char *name)
{
	int i;

	i = 0;
	if (*name == '\0')
		return (-1);
	while (name[++i] != '\0')
    {
    	if (name[i] == '=')
			return (i);
    	if (name[i] == '+' && name[i + 1] == '=')
			return (i + 1);
    }
	return (0);
}

/* Return 1 if this token is a legal shell `identifier'; that is, it consists
   solely of letters, digits, and underscores, and does not begin with a
   digit. */
int legal_identifier(char *name)
{
	int i;

	i = 0;
	if (*name == '\0' || !legal_var(name[i], FT_TRUE))
		return (0);
	while (name[++i] != '\0')
    	if (legal_var(name[i], FT_FALSE) == 0)
			return (0);
	return (1);
}

/* Check if the vars that we think are important are inherited.
   if not we make our own defaults. */
t_uint8 is_important(char *name, t_uint8 flag)
{
	t_uint8 impt;

	impt = 0x0;
	if (!(flag & IMPT_PATH) && ft_strncmp(name, "PATH=", 6) == 0)
		impt |= IMPT_PATH;
	if (!(flag & IMPT_PWD) && ft_strncmp(name, "PWD=", 5) == 0)
		impt |= IMPT_PWD;
	if (!(flag & IMPT_OLDPWD) && ft_strncmp(name, "OLDPWD=", 8) == 0)
		impt |= IMPT_OLDPWD;
	if (!(flag & IMPT_SHLVL) && ft_strncmp(name, "SHLVL=", 7) == 0)
		impt |= IMPT_SHLVL;
	return (impt);
}

static void swap(t_var *var1, t_var *var2)
{
	t_var tmp;

	tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}

void qsort_var(t_var *vars, size_t len)
{
	int i;
	int pvt;

	i = -1;
	pvt = 0;
    if (len <= 1)
        return;

    while (++i < len - 1)
	{
        if (ft_strcmp(vars[i].name, vars[len - 1].name) < 0)
            swap(vars + i, vars + pvt++);
	}
    swap(vars + pvt, vars + len - 1);
    qsort_var(vars, pvt++);
    qsort_var(vars + pvt, len - pvt);			
}
