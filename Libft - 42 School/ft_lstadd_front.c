#include "libft.h"

void	ft_lstadd_front(t_list	**lst, t_list	*new)
{
	if (!new)
		return ;
	if (!lst || !(*lst))
	{
		lst = &new;
		return ;
	}
	new->next = (*lst);
	(*lst) = new;
}

/*int	main(void)
{
	t_list	*lst1;
	t_list	**lst;
	t_list	*new;
	int	n;
	int	newnum;

	n = 5;
	newnum = 0;
	lst1 = malloc(sizeof(t_list));
	if (!lst1)
		return (0);
	lst1->content = &n;
	lst1->next = NULL;

	lst = &lst1;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	
	new->content = &newnum;
	new->next = NULL;

	printf("%i\n", *((int *)(*lst)->content));
	printf("%i\n", *((int *)new->content));
	
	ft_lstadd_front(lst, new);

	printf("%i\n", *((int *)(*lst)->content));
	printf("%i\n", *((int *)(*lst)->next->content));
	free((*lst)->next);

	ft_lstadd_front(NULL, new);

	lst1 = NULL;
	lst = &lst1;
	ft_lstadd_front(lst, new);
	free(new);
}*/
