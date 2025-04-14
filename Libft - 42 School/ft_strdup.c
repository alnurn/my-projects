#include "libft.h"

char	*ft_strdup(const char	*s)
{
	size_t	i;
	size_t	len;
	char	*cp;

	if (!s)
		return (NULL);
	len = 0;
	i = 0;
	while (s[len])
		len++;
	cp = (char *) malloc((len + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	while (s[i] && i < len)
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

/*int	main(void)
{
    const char *original = "Hello, world";
    char *copy;

    copy = ft_strdup(original);

    if (copy == NULL)
    {
        printf("Error: memory allocation failed\n");
        return (1);
    }

    printf("Original: %s\n", original);
    printf("Copy:     %s\n", copy);

    free(copy);

    return (0);
}*/
