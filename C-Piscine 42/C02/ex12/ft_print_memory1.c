/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:33:36 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/11 14:28:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_str_print(char	*addr, unsigned int pos, unsigned int size)
{
	unsigned int	j;
	char			ptr[17];

	j = 0;
	ptr[16] = '\0';
	while (j < 16 && (j + pos) < size)
	{
		if (!(addr[j] >= ' ' && addr[j] <= '~'))
			ptr[j] = '.';
		else
			ptr[j] = addr[j];
		j++;
	}
	write(1, ptr, j);
	write(1, "\n", 1);
}

void	ft_hex_convert(char	*hex, long unsigned int num, int n)
{
	char	*c;
	int		i;

	c = "0123456789abcdef";
	i = n - 1;
	while (i >= 0)
	{
		hex[i] = c[num % 16];
		num /= 16;
		i--;
	}
}

void	ft_collect(char	*hex_line, char	*ptr
	, unsigned int pos, unsigned int size)
{
	char			hex[3];
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	hex[2] = '\0';
	while (j < 16 && (j + pos) < size)
	{
		ft_hex_convert(hex, ptr[j], 2);
		hex_line[i] = hex[0];
		hex_line[i + 1] = hex[1];
		i += 2;
		if (j % 2)
		{
			hex_line[i] = ' ';
			i++;
		}
		j++;
	}
	while (i < 40)
	{
		hex_line[i] = ' ';
		i++;
	}
}

void	*ft_print_memory(void	*addr, unsigned int size)
{
	unsigned int	i;
	char			*ptr;
	char			hex_addr[17];
	char			hex_line[41];

	i = 0;
	ptr = (char *) addr;
	hex_addr[16] = '\0';
	hex_line[40] = '\0';
	while (i < size)
	{
		ft_hex_convert(hex_addr, (long unsigned int)&ptr[i], 16);
		write(1, hex_addr, 16);
		write(1, ": ", 2);
		ft_collect(hex_line, &ptr[i], i, size);
		write(1, hex_line, 40);
		ft_str_print(&ptr[i], i, size);
		i += 16;
	}
	return (addr);
}

/*int	main(void)
{
	char	*ptr;
	int	n[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	ptr = "Bonjour les aminabcdef";
	ft_print_memory(ptr, 22);
	write(1, "\n", 1);
	ft_print_memory(n, 40);
	write(1, "\n", 1);
}*/
