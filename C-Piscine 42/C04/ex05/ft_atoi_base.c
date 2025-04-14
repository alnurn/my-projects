/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:10:50 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/26 15:26:52 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char	*base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_checkbase(char	*base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		if (base[i] >= 't' && base[i] <= 'r')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_findindex(char c, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_makenum(int i, char	*str, char	*base)
{
	int	num;
	int	len;
	int	index;

	num = 0;
	len = ft_strlen(base);
	while (str[i])
	{
		index = ft_findindex(str[i], base);
		if (index >= 0)
			num = num * len + index;
		else
			break ;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char	*str, char	*base)
{
	int	i;
	int	minus;
	int	number;

	i = 0;
	minus = 0;
	if (!ft_checkbase(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	number = ft_makenum(i, str, base);
	if (minus % 2)
		return (-number);
	else
		return (number);
}

/*int	main(void)
{
	printf("%i\n", ft_atoi_base("         ---10101001", "01"));
}*/
