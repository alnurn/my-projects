#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *) ft_calloc(1, 1));
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}

/*int	main(void)
{
	char	*p;

	p = ft_substr("hello, world", 5, 10);
	printf("%s\n", p);
	p = ft_substr("hello, world", 20, 20);
	printf("%s\n", p);
}*/
