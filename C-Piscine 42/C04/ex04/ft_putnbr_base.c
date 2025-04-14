/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 03:44:29 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/23 20:12:58 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_checkbase(char	*base)
{
	int	i;
	int	j;

	i = 0;
	if (!ft_strlen(base) || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
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

void	recuprint(long n, char	*base)
{
	int	len;
	int	rem;

	len = ft_strlen(base);
	rem = n % len;
	if (n > len - 1)
		recuprint(n / len, base);
	write(1, &base[rem], 1);
}

void	ft_putnbr_base(int nbr, char	*base)
{
	long	n;

	if (!ft_checkbase(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -1 * (long)nbr;
	}
	else
		n = nbr;
	recuprint(n, base);
}

/*int	main(void)
{
	ft_putnbr_base(-2147483648, "01");
	write(1, "\n", 1);
}*/
