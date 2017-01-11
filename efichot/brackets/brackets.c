#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
	int o;
	char list[1000];
	int c;
	int a;
	int p;
	int k;

	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	c = 0;
	while (c < 1000)
	{
		list[c++] = '\0';
	}
	
	i = 1;
	while (i < ac)
	{
		k = 0;
		p = 0;
		c = 0;
		a = 0;
		j = 0;
		o = 1;
		while (av[i][j])
		{
			while (av[i][j] != '(' && av[i][j] != '{' && av[i][j] != '[' && av[i][j] != ')' && av[i][j] != '}' && av[i][j] != ']' && av[i][j])
				j++;	
			if (av[i][j] == '(')
			{
				p++;
				list[k++] = 'p';
				j++;
			}
			if (av[i][j] == '{')
			{
				a++;
				list[k++] = 'a';
				j++;
			}
			if (av[i][j] == '[')
			{
				c++;
				list[k++] = 'c';
				j++;
			}
			if (av[i][j] == ')')
			{
				if (!p)
				{
					o = 0;
					av[i][j] = '\0';
				}
				else
				{
					p--;
					if (list[--k] == 'p')
					{
						list[k] = '\0';
						j++;
					}
					else
					{
						o = 0;
						av[i][j] = '\0';
					}
				}
			}
			else if (av[i][j] == '}')
			{
				if (!a)
				{
					o = 0;
					av[i][j] = '\0';
				}
				else
				{
					a--;
					if (list[--k] == 'a')
					{
						list[k] = '\0';
						j++;
					}
					else
					{
						o = 0;
						av[i][j] = '\0';
					}
				}
			}
			else if (av[i][j] == ']')
			{
				if (!c)
				{
					o = 0;
					av[i][j] = '\0';
				}
				else
				{
					c--;
					if (list[--k] == 'c')
					{
						list[k] = '\0';
						j++;
					}
					else
					{
						o = 0;
						av[i][j] = '\0';
					}
				}
			}
			
		}
		if (!(av[i][j]))
			{
				if (o)
					write(1, "OK\n", 3);
				else
					write(1, "Error\n", 6);
			}
		i++;
	}
	return (0);
}
