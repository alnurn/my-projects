#include "libft.h"

/*static void	ft_delete(void	*content)
{
	if (!content)
		return ;
	content = NULL;
	printf("deleted\n");
}*/

static void	ft_recursive(t_list	*lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	ft_recursive(lst->next, del);
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list	**lst, void (*del)(void	*))
{
	if (!lst || !(*lst) || !del)
		return ;
	ft_recursive(*lst, del);
	*lst = NULL;
}

/*void	ft_print(t_list	*lst)
{
	if (!lst)
		return ;
	printf("%i\n", *((int *)lst->content));
	ft_print(lst->next);
}

int	main(void)
{
	int	p[5];
	int	i;
	t_list	*new;
	t_list	*first;
	t_list	**lst;

	i = 0;
	while (i < 5)
	{
		p[i] = i;
		i++;
	}
	i = 0;
	first = ft_lstnew(&p[i]);
	if (!first)
		return (0);
	first->next = NULL;
	lst = &first;
	i++;
	while (i < 5)
	{
		new = ft_lstnew(&p[i]);
		if (!new)
			return (0);
		ft_lstadd_back(lst, new);
		i++;
	}
	ft_print(*lst);
	ft_lstclear(lst, ft_delete);
}*/
