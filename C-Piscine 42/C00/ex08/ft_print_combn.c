/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:07:11 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/23 15:30:53 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char	*c, int n)
{
	int		i;
	int		count;
	char	max;

	i = 0;
	count = 0;
	max = '9' - n + 1;
	while (c[i])
	{
		write(1, &c[i], 1);
		if (c[i] == max)
			count++;
		i++;
		max++;
	}
	if (n != count)
		write(1, ", ", 2);
}

void	ft_increment(char	*c, char	*max, int pos, int n)
{
	while (c[pos] <= max[pos])
	{
		ft_print(c, n);
		if (c[pos] >= max[pos])
			break ;
		else
			c[pos]++;
	}
}

int	ft_reset(char	*c, char	*max, int pos, int n)
{
	int	cur_pos;

	c[pos]++;
	cur_pos = pos;
	while (pos < n)
	{
		c[pos + 1] = c[pos] + 1;
		pos++;
	}
	if (c[cur_pos] == max[cur_pos])
		return (cur_pos);
	else
		return (pos);
}

void	ft_coordinate(char	*c, char	*max, int n)
{
	int	pos;

	if (n == 10)
	{
		ft_print(c, n);
		return ;
	}
	pos = n - 1;
	while (pos >= 0)
	{
		ft_increment(c, max, pos, n);
		if (pos > 0 && c[pos - 1] < max[pos - 1])
			pos = ft_reset(c, max, pos - 1, n - 1);
		else
			pos--;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	c[11];
	char	max[11];

	i = 0;
	while (i < 11)
	{
		if (i < n)
		{
			c[i] = '0' + i;
			max[i] = '9' - (n - i) + 1;
		}
		else
		{
			c[i] = '\0';
			max[i] = '\0';
		}
		i++;
	}
	ft_coordinate(c, max, n);
}

/*int	main(void)
{
	ft_print_combn(4);
}*/
