#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	int			i;
	char const	*start;
	char const	*end;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = &s1[i];
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	end = &s1[i];
	if (start > end)
		return ((char *) ft_calloc(1, 1));
	i = (int)(end - start) + 1;
	return (ft_substr(start, 0, (size_t) i));
}

/*int	main(void)
{
	printf("1) ,,,ohello, worldo,,\n");
	printf("%s\n", ft_strtrim(",,,ohello, worldo,,", "o,"));
	
	printf("2) ,,,o,,,\n");
	printf("%s\n", ft_strtrim(",,,o,,,", ",,,,,,  "));

	printf("3) o.....\n");
	printf("%s\n", ft_strtrim("o.....", ". ,"));

	printf("4) .....o\n");
	printf("%s\n", ft_strtrim(".....o", ". ,"));
	
	printf("5) \n");
	printf("%s\n", ft_strtrim("", ""));

	printf("6) hello, world \n");
	printf("%s\n", ft_strtrim("hello, world", ""));

	printf("7) \n");
	printf("%s\n", ft_strtrim("", "hello, world"));

	printf("8) ' '\n");
	printf("%s\n", ft_strtrim(" ", " "));

	printf("9) ,,,,,,\n");
	printf("%s\n", ft_strtrim(",,,,,,",",,,,,"));

	printf("10) hello, world\n");
	printf("%s\n", ft_strtrim("hello, wolrd", ", "));

	printf("11) Hello, world\n");
	printf("%s\n", ft_strtrim("hello, world", NULL));

	printf("12) NULL\n");
	if (!ft_strtrim(NULL, " "))
		printf("NULL\n");
}*/
