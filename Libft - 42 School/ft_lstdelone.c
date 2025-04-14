#include "libft.h"

/*static void	ft_del(void	*content)
{
	free(content);
}*/

void	ft_lstdelone(t_list	*lst, void (*del)(void	*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*int	main(void)
{
	t_list	*ptr;
	int	*n;

	ptr = (t_list *) malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	n = (int *) malloc(2 * sizeof(int));
	n[0] = 5;
	ptr->content = n;
	ptr->next = NULL;
	printf("%i\n", *((int *)ptr->content));
	ft_lstdelone(ptr, ft_del);
}*/
