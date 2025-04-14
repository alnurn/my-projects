/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:33:36 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/11 14:28:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_puthex(int rem)
{
	char	*c;

	c = "0123456789abcdef";
	write(1, &c[rem], 1);
}

void	ft_putnbr(int n)
{
	int	rem;

	if (n < 0)
		n = -n;
	rem = n % 16;
	if (n > 15)
		ft_putnbr(n / 16);
	ft_puthex(rem);
}

void	ft_putstr_non_printable(char	*str)
{
	char	backslash;
	int		decimal;

	backslash = 92;
	while (*str)
	{
		if (*str >= ' ' && *str <= '~')
			write(1, str, 1);
		else
		{
			decimal = (int) *str;
			write(1, &backslash, 1);
			if (decimal < 16)
				write(1, "0", 1);
			ft_putnbr(decimal);
		}
		str++;
	}
}

/*int	main(void)
{
	ft_putstr_non_printable("Coucou\n\ntu vas bien ?");
	ft_putstr_non_printable("\x01");
	ft_putstr_non_printable("\x1F");
}*/
