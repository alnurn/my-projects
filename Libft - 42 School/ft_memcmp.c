#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	if (!n)
		return (0);
	i = 0;
	ptr1 = (const unsigned char *) s1;
	ptr2 = (const unsigned char *) s2;
	while (ptr1[i] == ptr2[i] && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}

/*int	main(void)
{
	printf("%i\n", ft_memcmp("hello, world", "hello, wo", 13));
}*/
