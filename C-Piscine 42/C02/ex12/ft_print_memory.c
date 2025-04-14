/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:33:36 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/11 14:28:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_hex_addprint(long unsigned int num)
{
	char	hex_addr[19];
	char	*c;
	int		i;

	hex_addr[18] = '\0';
	hex_addr[17] = ' ';
	hex_addr[16] = ':';
	c = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		hex_addr[i] = c[num % 16];
		num /= 16;
		i--;
	}
	write(1, hex_addr, 18);
}

void	ft_hex_print(int num)
{
	char	hex[3];
	char	*c;
	int		i;

	hex[2] = '\0';
	c = "0123456789abcdef";
	i = 1;
	while (i >= 0)
	{
		hex[i] = c[num % 16];
		num /= 16;
		i--;
	}
	write(1, hex, 2);
}

void	ft_char_print(int n)
{
	char	c;

	if (n >= ' ' && n <= '~')
		c = (char) n;
	else
		c = '.';
	write(1, &c, 1);
}

void	ft_line_print(void	*addr, unsigned int pos, unsigned int size, int s)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && (i + pos) < size)
	{
		ft_hex_print(*(int *)(addr + i));
		s += 2;
		if (i % 2)
		{
			write(1, " ", 1);
			s++;
		}
		i++;
	}
	while (s < 40)
	{
		write(1, " ", 1);
		s++;
	}
	i = 0;
	while (i < 16 && (i + pos) < size)
	{
		ft_char_print(*(char *)(addr + i));
		i++;
	}
}

void	*ft_print_memory(void	*addr, unsigned int size)
{
	unsigned int	i;
	void			*start;

	i = 0;
	start = addr;
	while (i < size)
	{
		if (!(i % 16))
		{
			ft_hex_addprint((long unsigned int) addr);
			ft_line_print(addr, i, size, 0);
			write(1, "\n", 1);
		}
		addr++;
		i++;
	}
	return (start);
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
