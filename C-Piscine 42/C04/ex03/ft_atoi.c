/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:56:03 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/20 15:34:43 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char	*str)
{
	int	i;
	int	m;
	int	num;
	int	n;

	i = 0;
	m = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = str[i] - '0';
		num = 10 * num + n;
		i++;
	}
	if (m % 2)
		return (-num);
	return (num);
}

/*int	main(void)
{
	char	*str;

	str = "   \n  ---+-+-1234ab567";
	printf("%i\n", atoi(str));
}*/
