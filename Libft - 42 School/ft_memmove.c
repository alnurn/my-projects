#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest || !src || !n || dest == src)
		return (dest);
	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else if (s > d)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	n[6] = "Hello";
	printf("%s\n", (char *) ft_memmove((n + 3), n, 6));
}*/
