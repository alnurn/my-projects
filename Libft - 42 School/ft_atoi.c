#include "libft.h"

int	ft_atoi(const char	*nptr)
{
	size_t	i;
	int		m;
	int		num;
	int		n;

	i = 0;
	m = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		i++;
		m = -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = nptr[i] - '0';
		num = 10 * num + n;
		i++;
	}
	return (num * m);
}

/*int	main(void)
{
	printf("%i\n", ft_atoi("   +42"));
}*/
