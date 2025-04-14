/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:31:26 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/22 21:07:26 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str);
int	ft_findindex(char c, char	*base_from);

int	ft_basecheck(char	*base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		if (base[i] >= '\t' && base[i] <= '\r')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char	*nbr, char	*base_from)
{
	int	i;
	int	len;
	int	minus;
	int	number;

	i = 0;
	minus = 0;
	number = 0;
	len = ft_strlen(base_from);
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			minus++;
		i++;
	}
	while (ft_findindex(nbr[i], base_from) >= 0)
	{
		number = number * len + ft_findindex(nbr[i], base_from);
		i++;
	}
	if (minus % 2)
		number *= -1;
	return (number);
}

void	ft_putnbr_base(long num, char	*base_to, char	*final, int count)
{
	int	len;
	int	remainder;

	if (num < 0)
	{
		final[0] = '-';
		num = -num;
	}
	len = ft_strlen(base_to);
	remainder = num % len;
	if (num > len - 1)
		ft_putnbr_base(num / len, base_to, final, count - 1);
	final[count] = base_to[remainder];
}

int	ft_strlen_base(int number, char	*base_to)
{
	int	i;
	int	len;

	if (!number)
		return (1);
	i = 0;
	len = ft_strlen(base_to);
	while (number)
	{
		number /= len;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char	*nbr, char	*base_from, char	*base_to)
{
	int		number;
	int		size;
	char	*final;

	if (!ft_basecheck(base_from) || !ft_basecheck(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	size = ft_strlen_base(number, base_to);
	if (number < 0)
		size++;
	final = (char *) malloc((size + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	final[size] = '\0';
	ft_putnbr_base((long) number, base_to, final, size - 1);
	return (final);
}

/*int	main(void)
{
	char	*s;

	s = ft_convert_base("   \n   ++-80000000", "0123456789abcdef", "0123456789");
	printf("%s\n", s);
	return (0);
}*/
