#include "libft.h"

void	*ft_memset(void	*s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char	ptr[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		ptr[i] = '0';
		i++;
	}
	printf("%s\n", ptr);
	ft_memset(ptr, 49, 5);
	printf("%s\n", ptr);
}*/
