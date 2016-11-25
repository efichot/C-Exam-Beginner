int ft_atoi_base(const char *str, int str_base)
{
	char basemin[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	char basemaj[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int i;
	int neg;
	int ret;
	
	i = 0;
	neg = 0;
	ret = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
			i++;
		if (str[i] == '-')
			neg = 1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str_base <= 10)
		{
			while (str[i] >= '0' && str[i] <= basemin[str_base - 1] && str[i])
			{
				ret *= str_base;
				ret += str[i] - '0';
				i++;
			}
		}
		
		else if (str_base > 10)
		{
			while (((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= basemin[str_base - 1]) || (str[i] >= 'A' && str[i] <= basemaj[str_base - 1])) && str[i])
			{
				ret *= str_base;
				if (str[i] >= '0' && str[i] <= '9')
					ret += str[i] - '0';
				if (str[i] >= 'a' && str[i] <= 'f')
				{ 
					ret += str[i] - 87;
				}
				if (str[i] >= 'A' && str[i] <= 'F')
				{
					ret += str[i] - 55;
				}
				i++;
			}
		}
		if (neg)
		{
			return (-ret);
		}
		return (ret);
}
