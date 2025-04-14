#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*ptr;

	ptr = (t_list *) malloc (sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/*int	main(void)
{
	t_list	*ptr;
	int	*p;
	int	n;

	n = 5;
	p = &n;

	ptr = ft_lstnew(p);
	printf("%i\n", *((int *)ptr->content));
	free(ptr);
}*/
