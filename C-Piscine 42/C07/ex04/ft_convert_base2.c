/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:31:26 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/22 21:07:26 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_findindex(char c, char	*base_from)
{
	int	i;

	i = 0;
	while (base_from[i])
	{
		if (c == base_from[i])
			return (i);
		i++;
	}
	return (-1);
}
