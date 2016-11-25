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
	int count;
	int len;

	i = 0;
	count = 0;
	len = 0;
	j = 0;
	while (av[1][len])
	{
		len++;
	}
	while (av[1][i])
	{
		while (av[1][i] != av[2][j] && av[1][i] && av[2][j])
		{
			j++;
		}
		
		if (av[1][i] == av[2][j])
		{
			count++;
		}
		i++;
	}
	if (count == len)
	{
		write(1, "1\n", 2);
	}
	else
	{
		write(1, "0\n", 2);
	}
	return (0);
}
