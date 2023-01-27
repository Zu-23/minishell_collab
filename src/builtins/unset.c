#include "minishell.h"

/*
** $BUILTIN unset
** $FUNCTION unset_builtin
** $SHORT_DOC unset [name ...]
** Unset values and attributes of shell variables.
*/
int unset_builtin(char *av[])
{
	if (av[1] == NULL)
		return (EXEC_SUCC);
	while (*(av++ + 1))
	{
		if (legal_identifier(*av) == 0)
			return (EXEC_FAIL);
		del_var(*av);
	}
	return (EXEC_SUCC);
}