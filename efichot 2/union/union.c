#include <unistd.h>

int main(int ac , char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i;
	int j;
	int len;
	int k;

	i = 0;
	len = 0;
	while (av[1][len])
	{
		len++;
	}
	len--;
	while (av[1][i])
	{
		j = i - 1;
		while (j >= 0)
		{
			if (av[1][i] != av[1][j])
			{
				j--;
			}
			if (av[1][i] == av[1][j])
			{
				j = -2;
			}
		}
		if (j == -1)
		{
			write(1, &av[1][i], 1);
		}
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		j = i - 1;
		k = len;
		while (j >= 0)
		{
			if (av[2][i] != av[2][j])
			{
				j--;
			}
			if (av[2][i] == av[2][j])
			{
				j = -2;
			}
		}
		if (j == -1)
		{
			while (av[1][k] != av[2][i] && k >= 0)
			{
				k--;
			}
			if (k == -1 && len > 1)
				write(1, &av[2][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
