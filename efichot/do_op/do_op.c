#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("\n");
		return (0);
	}
	int nb1;
	int nb2;
	char s;

	nb1 = atoi(av[1]);
	nb2 = atoi(av[3]);
	s = av[2][0];
	if (s == '+')
	{
		printf("%d\n", nb1 + nb2);
	}
	if (s == '-')
	{
		printf("%d\n", nb1 - nb2);
	}
	if (s == '*')
	{
		printf("%d\n", nb1 * nb2);
	}
	if (s == '/')
	{
		printf("%d\n", nb1 / nb2);
	}
	if (s == '%')
	{
		printf("%d\n", nb1 % nb2);
	}
	return (0);
}
