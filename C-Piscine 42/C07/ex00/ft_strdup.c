/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:13:21 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/19 10:41:08 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*src)
{
	int		len;
	int		i;
	char	*cp;

	i = 0;
	len = ft_strlen(src);
	cp = (char *) malloc((len + 1) * sizeof(char));
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[len] = '\0';
	return (cp);
}
