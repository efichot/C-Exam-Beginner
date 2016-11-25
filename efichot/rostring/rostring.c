#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		int i;
		int len_word;
		int nb_word;
		int max_len_word;
		char **tab;
		int j;
		int k;

		i = 0;
		nb_word = 0;
		max_len_word = 0;
		while (av[1][i])
		{
			while ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i])
				i++;
			len_word = 0;
			if (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
			{
				nb_word++;
				while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
				{
					len_word++;
					if (len_word > max_len_word)
						max_len_word = len_word;
					i++;
				}
			}
		}
		tab = (char **)malloc(sizeof(*tab) * nb_word + 1);
		i = 0;
		j = 0;
		while (av[1][i])
		{
			while ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i])
                i++;
			if (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
			{
				tab[j] = (char *)malloc(sizeof(**tab) * max_len_word + 1);
				k = 0;
				while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
                {
					tab[j][k] = av[1][i];
					k++;
					i++;
				}
				tab[j][k] = '\0';
				j++;
			}
		}
		tab[j] = 0;
		j = 1;
		while (tab[j])
		{
			ft_putstr(tab[j]);
			write(1, " ", 1);
			j++;
		}
		ft_putstr(tab[0]);
		write(1, "\n", 1);
	}
	return (0);
}
