/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:20:44 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/11 18:40:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char n)
{
	if (n >= 'A' && n <= 'Z')
		return (1);
	else if (n >= 'a' && n <= 'z')
		return (2);
	else if (n >= '0' && n <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_check(str[i]) == 1)
			str[i] += 32;
		i++;
	}
	i = 0;
	if (ft_check(str[i]) == 2)
		str[i] -= 32;
	i++;
	while (str[i])
	{
		if (ft_check(str[i - 1]) == 0 && ft_check(str[i]) == 2)
			str[i] -= 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	n[64] = " salut, comment tu vas ? 42mots 
	quarante-deux; cinquante+et+un ";
	char	*c;
	
	c = ft_strcapitalize(n);
	printf("%s\n", c);
}*/
