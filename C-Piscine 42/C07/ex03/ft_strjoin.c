/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:31:26 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/22 21:07:26 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_totalen(int size, char **strs, char *sep)
{
	int	i;
	int	totalen;

	i = 0;
	totalen = 0;
	while (i < size)
	{
		totalen += ft_strlen(strs[i]);
		i++;
	}
	totalen += (size - 1) * ft_strlen(sep);
	return (totalen);
}

char	*ft_strcpy(char	*strsep, char	*str)
{
	while (*strsep)
	{
		*str = *strsep;
		strsep++;
		str++;
	}
	return (str);
}

char	*ft_finalstr(int size, char	**strs, char *sep, char	*str)
{
	int		i;
	char	*start;

	i = 0;
	start = str;
	while (i < size)
	{
		str = ft_strcpy(strs[i], str);
		if (i < size - 1)
			str = ft_strcpy(sep, str);
		i++;
	}
	str = start;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		totalen;

	if (!size)
	{
		str = (char *) malloc(1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	totalen = ft_totalen(size, strs, sep);
	str = (char *) malloc((totalen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[totalen] = '\0';
	str = ft_finalstr(size, strs, sep, str);
	printf("TOTALEN: %i\n", totalen);
	return (str);
}

/*int	main(int argc, char **argv)
{
	char	*sep;
	char	*str;

	sep = ", ";
	str = ft_strjoin(argc, argv, sep);
	printf("%s\n", str);
	printf("STRLEN: %i\n", ft_strlen(str));
}*/
