#include "list.h"
t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *parent;
	t_list *begin_list;
	t_list *enfant;

	begin_list = lst;
	while (lst)
	{
		enfant = lst->next;
		if (parent)
		{
			if (cmp(parent->data, lst->data) == 0)
			{
				lst->next = parent;
				parent->next = enfant;
				lst = begin_list;
			}
		}
		parent = lst;
		lst = lst->next;
	}
	return (begin_list);
}
