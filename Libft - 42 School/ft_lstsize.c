#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int		i;
	t_list	*ptr;

	if (!lst)
		return (0);
	i = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/*void	ft_free(t_list	*lst)
{
	if (!lst)
		return ;
	printf("%i\n", *((int *)lst->content));
	ft_free(lst->next);
	free(lst);
}

int	main(void)
{
	int	p[10];
	int	i;
	t_list	*new;
	t_list	*first;
	t_list	**lst;

	i = 0;
	while (i < 10)
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
	while (i < 10)
	{
		new = ft_lstnew(&p[i]);
		if (!new)
			return (0);
		ft_lstadd_front(lst, new);
		i++;
	}
	printf("SIZE: %i\n", ft_lstsize(*lst));
	ft_free(*lst);
}*/
