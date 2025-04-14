/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:39:31 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/12 14:58:07 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char	*dest, char	*src)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (dest[n])
		n++;
	while (src[i])
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	s2[30];
	char	*s1;

	s1 = "Hello, world";
	printf("%s\n", ft_strcat(s2, s1));
}*/
