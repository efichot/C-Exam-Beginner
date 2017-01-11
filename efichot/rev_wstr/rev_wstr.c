#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int nb_word;
	int len_word;
	int max_len_word;
	int i;
	char **tab;
	int j;
	int k;

	i = 0;
	nb_word = 0;
	max_len_word = 0;
	while (av[1][i])
	{
		if (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
		{
			nb_word++;
			len_word = 0;
			while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
			{
				len_word++;
				i++;
			}
			if (len_word > max_len_word)
				max_len_word = len_word;
		}
		if (av[1][i] == ' ' | av[1][i] == '\t')
			i++;
	}
	tab = (char **)malloc(sizeof(*tab) * nb_word + 1);
	i = 0;
	j = 0;
	while (av[1][i])
	{
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
		if (av[1][i] == ' ' | av[1][i] == '\t')
			i++;
	}
	tab[j] = 0;
	j--;
	while (j >= 0)
	{
		write(1, tab[j], ft_strlen(tab[j]));
		if (j)
			write(1," ", 1);
		j--;
	}
	write(1, "\n", 1);
	return (0);
}
