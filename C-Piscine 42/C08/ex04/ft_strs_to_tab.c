/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:27:41 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/25 18:28:11 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_len(char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char	*src, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ptr;

	ptr = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (NULL);
		ptr[i].size = ft_len(av[i]);
		ptr[i].str = ft_strdup(av[i], ptr[i].size);
		ptr[i].copy = ft_strdup(av[i], ptr[i].size);
		if (ptr[i].str == NULL || ptr[i].copy == NULL)
			return (NULL);
		i++;
	}
	ptr[i].str = NULL;
	return (ptr);
}

/* int	main(int argc, char **argv)
{
	struct s_stock_str	*ptr;

	ptr = ft_strs_to_tab(argc, argv);
	ft_show_tab(ptr);
	return (0);
} */
