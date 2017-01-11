#include <unistd.h>

void print_bits(unsigned char octet)
{
	int nb;
	int tab[8];
	char c;
	int i;

	nb = octet;
	i = 0;
	while (i < 8)
	{
		tab[i] = nb % 2;
		nb = nb / 2;
		i++;
	}
	i--;
	while (i >= 0)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i--;
	}
}
