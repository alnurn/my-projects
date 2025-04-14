int	ft_isascii(int c)
{
	if (!c)
		c = 1;
	else if (!(c > 0 && c <= 127))
		c = 0;
	return (c);
}
