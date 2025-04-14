/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 07:25:17 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/08 07:59:15 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int	*tab, int size)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	y = size - 1;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[y];
		tab[y] = temp;
		i++;
		y--;
	}
}
