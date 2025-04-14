/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:07:56 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/18 14:46:39 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	f;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	i = 1;
	f = 1;
	while (i <= nb)
	{
		f *= i;
		i++;
	}
	return (f);
}

/*int	main(void)
{
	printf("%i\n", ft_iterative_factorial(5));
}*/
