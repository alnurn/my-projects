/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:29:07 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/13 14:33:42 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	n;
	unsigned int	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (!size || size <= dest_len)
		return (size + src_len);
	i = 0;
	n = dest_len;
	while (src[i] && n < size - 1)
	{
		dest[n + i] = src[i];
		i++;
	}
	dest[n + i] = '\0';
	return (src_len + dest_len);
}

/*int	main(void)
{
	char	dest[12];
	char	*src;

	dest[0] = 'H';
	dest[1] = 'e';
	src = "llo, world";
	printf("%i\n", ft_strlcat(dest, src, 12));
	printf("%s\n", dest);

}*/
