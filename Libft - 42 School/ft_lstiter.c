#include "libft.h"

/*void	ft_modify(void	*content)
{
	if (!content)
		return ;
	*((int *)content) += 2;
}*/

void	ft_lstiter(t_list	*lst, void (*f)(void	*))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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
	printf("Before\n");
	ft_print(*lst);
	ft_lstiter(*lst, ft_modify);
	printf("After\n");
	ft_print(*lst);
}*/
