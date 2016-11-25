#include <stdlib.h>
char *ft_itoa_base(int value, int base)
{
	char bases[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char *ret;
	int tab[64];
	int neg;
	unsigned int nb;
	int i;
	int j;
	int k;
	
	neg = 0;
	i = 0;
	if (value == 0)
	{
		ret = (char *)malloc(sizeof(*ret) * 2);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		nb = -value;
	}
	else
	{
		nb = value;
	}
	while (nb != 0)
	{
		tab[i] = nb % base;
		nb = nb / base;
		i++;
	}
	ret = (char *)malloc(sizeof(*ret) * i + neg + 1);
	j = 0;
	if (neg)
	{
		ret[0] = '-';
		j++;
	}
	i--;
	k = i;
	while (j <= k + neg)
	{
		ret[j] = bases[tab[i]];
		j++;
		i--;
	}
	ret[j] = '\0';
	return (ret);
}
