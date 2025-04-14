#include "libft.h"

/*void	ft_delete(void	*content)
{
	if (!content)
		return ;
	content = NULL;
	printf("deleted\n");
}

void	*ft_modify(void	*content)
{
	if (!content)
		return (NULL);
	*((int *)content) += 2;
	return (content);
}*/

t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void	*), void (*del)(void *))
{
	t_list	*copy;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	copy = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&copy, del);
			return (NULL);
		}
		ft_lstadd_back(&copy, node);
		if (!copy)
			copy = node;
		lst = lst->next;
	}
	return (copy);
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
	t_list	*modcopy;

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
	printf("Initial list, before: \n");
	ft_print(*lst);

	modcopy = ft_lstmap(*lst, ft_modify, ft_delete);
	printf("Copy of the modified list\n");
	ft_print(modcopy);
}*/
