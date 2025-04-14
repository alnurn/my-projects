#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcat(dst, s1, len + 1);
	ft_strlcat(dst, s2, len + 1);
	return (dst);
}

/*int	main(void)
{
	printf("%s\n", ft_strjoin("hello ", "world"));
}*/
