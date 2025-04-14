#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
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
	t_list	*last;

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
	last = ft_lstlast(*lst);
	printf("LAST: %i\n", *((int *)last->content));
	ft_free(*lst);
}*/
