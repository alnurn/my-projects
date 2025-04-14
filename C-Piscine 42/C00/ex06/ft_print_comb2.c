/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:38:30 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/22 19:59:33 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(char a, char b)
{
	char	right[2];

	right[0] = a;
	right[1] = b + 1;
	while (right[0] <= '9')
	{
		while (right[1] <= '9')
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, " ", 1);
			write(1, &right[0], 1);
			write(1, &right[1], 1);
			if (!(a == '9' && b == '8' && right[0] == '9' && right[1] == '9'))
				write(1, ", ", 2);
			right[1]++;
		}
		right[0]++;
		right[1] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	left[2];

	left[0] = '0';
	while (left[0] <= '9')
	{
		left[1] = '0';
		while (left[1] <= '9')
		{
			ft_print_comb(left[0], left[1]);
			left[1]++;
		}
		left[0]++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
}*/
