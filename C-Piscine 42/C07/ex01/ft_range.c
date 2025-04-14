/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:28:48 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/19 18:14:46 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
		return (0);
	ptr = (int *) malloc((max - min) * sizeof(int));
	if (ptr == 0)
		return (0);
	i = min;
	while (i < max)
	{
		ptr[i - min] = i;
		i++;
	}
	return (ptr);
}

/*int	main(void)
{
	int	i;
	int	*ptr;

	i = 2;
	ptr = ft_range(2, 10);
	while (i < 10)
	{
		printf("%i\n", ptr[i - 2]);
		i++;
	}
}*/
