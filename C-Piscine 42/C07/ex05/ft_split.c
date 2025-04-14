/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:31:26 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/22 21:07:26 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_separator(char c, char	*charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_countwords(char	*str, char	*charset)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (!ft_is_separator(*str, charset) && !flag)
		{
			flag = 1;
			count++;
		}
		if (ft_is_separator(*str, charset))
			flag = 0;
		str++;
	}
	return (count);
}

char	*ft_strndup(char	*str, int n)
{
	int		i;
	char	*dest;

	dest = (char *) malloc((n + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

char	**ft_split(char	*str, char	*charset)
{
	int		i;
	int		icount;
	int		start;
	char	**res;

	res = (char **) malloc((ft_countwords(str, charset) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[ft_countwords(str, charset)] = 0;
	i = 0;
	icount = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !ft_is_separator(str[i], charset))
			i++;
		res[icount] = ft_strndup(&str[start], i - start);
		icount++;
	}
	return (res);
}

/*int	main(void)
{
	char	*str;
	char	*charset;
	char	**library;
	int		n;
	int		i;

	str = ",,,,,Hello world, I hope, that I will pass the piscine,";
	charset = ", ";
	i = 0;
	n = ft_countwords(str, charset);
	library = ft_split(str, charset);
	while (i < n)
	{
		printf("%s\n", library[i]);
		i++;
	}
	return (0);
}*/
