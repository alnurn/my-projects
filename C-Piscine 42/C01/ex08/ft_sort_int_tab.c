/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 08:01:31 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/08 08:27:08 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int	*tab, int size)
{
	int	x;
	int	y;
	int	temp;

	x = 0;
	while (x < size - 1)
	{
		y = x + 1;
		while (y < size)
		{
			if (tab[x] > tab[y])
			{
				temp = tab[y];
				tab[y] = tab[x];
				tab[x] = temp;
			}
			y++;
		}
		x++;
	}
}
