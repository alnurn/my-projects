#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len)
{
	size_t	h;
	size_t	i;
	size_t	n_len;

	h = 0;
	n_len = 0;
	while (needle[n_len])
		n_len++;
	if (!n_len)
		return ((char *) haystack);
	while (haystack[h] && (h + n_len) <= len)
	{
		i = 0;
		while (haystack[h + i] && needle[i]
			&& ((unsigned char) haystack[h + i] == (unsigned char) needle[i]))
			i++;
		if (i == n_len)
			return ((char *) &haystack[h]);
		h++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	*s;

	s = "hello, world";
	s = ft_strnstr("hello, world", "e", 3);
	if (s == NULL)
		printf("NULL\n");
	else
		printf("%s\n", s);
}*/
