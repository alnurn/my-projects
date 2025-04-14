/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:39 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/12 16:11:22 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char	*dest, char	*src, unsigned int nb)
{
	unsigned int	n;
	unsigned int	i;

	n = 0;
	i = 0;
	while (dest[n])
		n++;
	while (src[i] && i < nb)
	{
		dest[n] = src[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	s2[30];
	char	*s1;

	s1 = "Hello, world";
	s2[0] = 'Y';
	s2[1] = '\0';
	printf("%s\n", ft_strncat(s2, s1, 5));
}*/
