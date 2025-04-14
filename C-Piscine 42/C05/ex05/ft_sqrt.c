/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:19:44 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/18 14:58:29 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	sq;

	if (nb < 0)
		return (0);
	i = 1;
	sq = 1;
	while (i <= nb)
	{
		sq = i * i;
		if (sq == nb)
			return (i);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%i\n", ft_sqrt(121));
}*/
