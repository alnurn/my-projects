#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t sz)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!sz)
		return (src_len);
	while (src[i] && i < sz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*int	main(void)
{
	char dst[5];
	
	printf("%zu\n", ft_strlcpy(dst, "Hello, world", 5));
	printf("%s\n", dst);
}*/
