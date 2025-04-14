/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:29:07 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/13 14:33:42 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_len(char	*to_find)
{
	unsigned int	i;

	i = 0;
	while (to_find[i])
		i++;
	return (i);
}

int	ft_strncmp(char	*str, char	*to_find, unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < nb - 1 && str[i] == to_find[i])
		i++;
	return (str[i] - to_find[i]);
}

char	*ft_strstr(char	*str, char	*to_find)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = ft_len(to_find);
	if (!len)
		return (str);
	while (str[i])
	{
		if (*to_find == str[i] && !ft_strncmp(&str[i], to_find, len))
			return (&str[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "Hello, world";
	s2 = ", ";
	printf("%s\n", ft_strstr(s1, s2));
}*/
