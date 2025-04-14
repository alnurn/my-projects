#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	size_t			i;
	unsigned char	n;

	i = 0;
	n = (unsigned char) c;
	while (s[i])
	{
		if (n == (unsigned char) s[i])
			return ((char *) &s[i]);
		i++;
	}
	if (n == (unsigned char) s[i])
		return ((char *) &s[i]);
	return (NULL);
}

/*int	main(void)
{
	char	*n;

	n = ft_strchr("hello, world", 'e');
	if (!n)
		printf("NULL\n");
	else
		printf("%s\n", n);

	n = ft_strchr("hello, world", 'a');
	if (!n)
		printf("NULL\n");
	else
		printf("%s\n", n);
	if (!n)
		printf("NULL\n");
	else
		printf("%s\n", n);
}*/
