#include <stdlib.h>
char *ft_itoa_base(int value, int base)
{
	int neg;
	int intlen;
	unsigned int nb;
	int tab[64];
	char bases[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char *ret;
	int i;
	int j;
	

	neg = 0;
	intlen = 0;
	if (value == 0)
	{
		ret = (char *)malloc(sizeof(*ret) * 2);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	if (base == 10 && value < 0)
	{
		neg = 1;
	}
	nb = (value < 0) ? -value : value;
	while (nb)
	{
		tab[intlen] = nb % base;
		nb = nb / base;
		intlen++;
	}
	ret = (char *)malloc(sizeof(*ret) * intlen + 1 + neg);
	i = 0;
	if (neg)
	{
		ret[0] = '-';
		i++;
	}
	j = intlen - 1;
	while (i < intlen + neg)
	{
		ret[i] = bases[tab[j]];
		i++;
		j--;
	}
	ret[i] = '\0';
	return (ret);
}
