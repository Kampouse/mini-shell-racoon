#include "../minishell.h"

char	*find_part(char *first, char *str, int inc, size_t **len)
{
	(void)len;
	if (!first)
	{
		printf("missid a (%c) \n", str[inc]);
		len = NULL;
		first = NULL;
		return (NULL);
	}
	len = NULL;
	return (first);
}
