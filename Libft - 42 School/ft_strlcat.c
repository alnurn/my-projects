#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t sz)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = 0;
	dst_len = 0;
	while (src[src_len])
		src_len++;
	while (dst[dst_len])
		dst_len++;
	if (sz <= dst_len)
		return (sz + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < sz - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

/*int	main(void) 
{
	char dest[10] = "Hello";
	const char src[20] = " World!";

	printf("Before strlcat: %s\n", dest);
	size_t result = ft_strlcat(dest, src, sizeof(dest));
	printf("After strlcat: %s\n", dest);
	printf("Returned value: %zu\n", result);
	printf("%i\n", dest[9]);
	return (0);
}*/
