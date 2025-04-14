/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 07:59:02 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:11 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	num;
	int	i;

	if (power < 0)
		return (0);
	if (!power)
		return (1);
	i = 0;
	num = 1;
	while (i < power)
	{
		num *= nb;
		i++;
	}
	return (num);
}

/*int	main(void)
{
	printf("%i\n", ft_iterative_power(3, 2));
}*/
