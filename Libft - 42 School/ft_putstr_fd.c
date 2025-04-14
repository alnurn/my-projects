#include "libft.h"

void	ft_putstr_fd(char	*s, int fd)
{
	size_t	i;

	if (!s || fd < 0)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
}

/*int	main(void)
{
	ft_putstr_fd("hello, world", 1);
}*/
