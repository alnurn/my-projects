#include "libft.h"

/*void	ft_capitalize(unsigned int n, char	*s)
{
	if (!s)
		return ;
	if (s[n] >= 'a' && s[n] <= 'z')
		s[n] -= 32;
}*/

void	ft_striteri(char	*s, void (*f)(unsigned int, char	*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f((unsigned int) i, s);
		i++;
	}
}

/*int	main(void)
{
	char	s[13] = "hello, world";

	s[12] = '\0';
	ft_striteri(s, ft_capitalize);
	printf("%s\n", s);
}*/
