/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:11:14 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/19 18:27:08 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int	**range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = min;
	while (i < max)
	{
		range[0][i - min] = i;
		i++;
	}
	return (max - min);
}

/*int	main(void)
{
	int	**range;
	int	*r;
	int	i;
	int	n;

	i = 0;
	n = 5;
	r = &n;
	range = &r;
	range = ft_ultimate_range(range, 1, 10);
	while (i < 9)
	{
		printf("%i\n", range[0][i]);
		i++;
	}
}*/
