#include "libft.h"

/*static char	ft_capitalize(unsigned int n, char c)
{
	(void) n;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*dst;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	dst = (char *) malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f((unsigned int) i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/*int	main(void)
{
	char	*s;

	s = "hello, world!";
	printf("BEFORE: %s\n", s);
	printf("AFTER: %s\n", ft_strmapi(s, ft_capitalize));
}*/
