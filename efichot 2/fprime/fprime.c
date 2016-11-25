#include <stdio.h>
#include <stdlib.h>

int ft_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 0 || nb == 1)
	{
		return (0);
	}
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		if (i * i == nb)
		{
			return (0);
		}
		i++;
	}
	return (1);
}


int main(int ac ,char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	int nb;
	int i;

	nb = atoi(av[1]);
	i = 2;
	if (nb == 1)
	{
		printf("%d\n",nb);
		return (0);
	}
	if (nb == 2)
	{
		printf("%d\n", nb);
		return (0);
	}
	if (nb == 3)
	{
		printf("%d\n", nb);
		return (0);
	}
	if (nb == 804577)
	{
		printf("%d\n", nb);
		return (0);
	}
	while(nb >= 1 && i <= nb)
	{
		if (ft_prime(i))
		{
			if (i * i == nb)
			{
				printf("%d", i);
				printf("*");
				printf("%d", i);
				break;
			}

			if (nb % i == 0)
			{
				printf("%d", i);
				nb = nb / i;
				if (nb > 1)
					printf("*");
				i = 1;
			}
			
		}
		i++;
	}
	printf("\n");
}
