#include "libft.h"

//DONT UNDERSTAND...

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	unsigned char			*dptr;
	const unsigned char		*sptr;
	size_t					i;

	if (!dest || !src)
		return (dest);
	if (dest == src)
		return (dest);
	i = 0;
	dptr = (unsigned char *) dest;
	sptr = (const unsigned char *) src;
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	dst[10];
	
	printf("%zu\n", sizeof(dst));
	ft_memcpy(dst,  NULL, sizeof(dst));
	ft_memcpy(NULL,  NULL, sizeof(dst));
	ft_memcpy(NULL,  dst, sizeof(dst));
	ft_memcpy(dst,  NULL, 0);
}*/
