#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*ptr;

	if (!new)
		return ;
	if (!lst || !(*lst))
	{
		lst = &new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
	new->next = NULL;
}

//not sure about the new->next = NULL

/*void	ft_free(t_list	*lst)
{
	if (!lst)
		return ;
	printf("BEFORE: %i\n", *((int *)lst->content));
	ft_free(lst->next);

	printf("AFTER: %i\n", *((int *)lst->content));
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
		ft_lstadd_back(lst, new);
		i++;
	}
	ft_free(*lst);
}*/
