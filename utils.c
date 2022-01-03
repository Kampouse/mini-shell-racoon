#include "minishell.h"

/* should clean all the data structures left
 on the  heap also return a status?*/
/*
int	exit_please(char **tokens, char *trimed)
{
	if (trimed && tokens)
	{
		if (find_token(tokens[0], "exit"))
		{
			printf("exit\n");
			free(trimed);
			freelist(tokens);
			return (1);
		}
	}
	return (0);
}
*/
int ft_isspace(char elm)
{
if(!elm)
	return(0);
if(elm == ' ' || elm == '\t' )
	return(1);
else if(elm == '\n' || elm == '\v' || elm == '\v' || elm == '\f' || elm == '\r')
	return(1);
return(0);
}

int until_space(char *str)
{
	int inc;
	inc = 0;
	if(!str)
		return(-1);
	while(!ft_isspace(str[inc]) && str[inc])
	{
		inc++;
	}
    return(inc);
}

void    freelist(char **list)
{
	int	index;

	index = 0;
	if(list)
	{
		while (list[index])
	    {
		    // if(list[index])
			free((void *)list[index]);
		    index++;
	    }
	    free(list);
	}
}

// return la longueur d'un char**
int ft_tab_len(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
        i++;
    return (i);
}

//Cette fonction trie un tableau de char en ordre ascii
char **ft_sort_tab(char **tab)
{
    int i;
    int j;
    char **temp_tab;
    char **tab_sorted;
    
    temp_tab = alloc_tab(tab);
    tab_sorted = tab;
    i = 0;
    while (i < ft_tab_len(tab))
    {
        j = 0;
        while (j < ft_tab_len(tab))
        {
            if (ft_strncmp(tab_sorted[i], tab[j], ft_strlen(tab_sorted[i])) < 0)
            {
                temp_tab[i] = tab_sorted[i];
                tab_sorted[i] = tab[j];
                tab[j] = temp_tab[i];
            }
            j++;
        }
        i++;
    }
	 free(temp_tab);
    return (tab_sorted);
}

//Cette fonction ajoute un nouvelle element a la liste "export"
char **add_to_list(char *new_exprt, char **old_list, int type)
{
    char **new_list;
    int i;

    new_list = NULL;
    new_list = malloc(sizeof(char *) * (ft_tab_len(old_list) + 2));
    i = 0;
    while (old_list[i])
    {
        new_list[i] = ft_strdup(old_list[i]);
        i++;
    }
    new_list[i] = ft_strdup(new_exprt);
    i++;
    new_list[i] = NULL;
	if (type)
    	return (ft_sort_tab(new_list));
	return (new_list);
    // print_exprt(ft_tab_len(g_state.exprt));
}

char **remove_of_list(char *to_remove, char **old_list)
{
    char **new_list;
    int i;
    int j;

    new_list = NULL;
    new_list = malloc(sizeof(char **) * (ft_tab_len(old_list) + 1));
    i = 0;
    j = 0;
    while (old_list[i])
    {
 		if (!ft_strncmp(old_list[i], to_remove, ft_strlen(to_remove)))
		{
		 	i++;
		}
		else
		{
		
			new_list[j] = ft_strdup(old_list[i]);
			i++;
			j++;
		}
    }
    new_list[j] = NULL;
    freelist(old_list);
    return (new_list);
}
