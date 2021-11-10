#include "../push_swap.h"
#include "stdio.h"
#include "stdlib.h"

t_dlist	*node_init(int content)
{
	t_dlist	*link;

	link = (t_dlist *)malloc(sizeof(*link));
  if (!link)
    return (NULL);
  link->content = content;
  link->prev = NULL;
  link->next = NULL;
  return (link);
}

t_dlist  *ft_lst_add_frontd(t_dlist **currlist, t_dlist *newnode)
	{
		t_dlist *temp;
		temp = *currlist;
  if (currlist)
	{
    if (*currlist)
		{
      newnode->next = *currlist;
	  temp->prev = newnode;
    }
    *currlist = newnode;
  }
  return (*currlist);
}
void ft_lst_add_backd(t_dlist **currlist, t_dlist *node) 
{
  t_dlist *last;

  if (currlist)
	{
    if (*currlist)
	{
      last = ft_lst_lastnode(*currlist);
      node->prev = last;
      last->next = node;
    } else
      *currlist = node;
  }

}

void	ft_clearnode(t_dlist *currlist, void (*del)(void *))
{
	if (currlist)
		free(currlist);
}

t_dlist	*ft_lstnew(int content)
{
	t_dlist	 *link;

	link = (t_dlist *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->content = content;
	link->next = NULL;
	return (link);
}
