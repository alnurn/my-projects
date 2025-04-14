#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char) c == (unsigned char) s[i])
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
