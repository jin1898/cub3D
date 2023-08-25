#include <stdio.h>
// #include "./srcs/libft.a"


int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int ft_check_arguments(char *str)
{
    int i = 0;

    while(str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return(0);
        i++;
    }
    return(1);
}
int main(void)
{
    printf("%d",ft_check_arguments("20a"));
}
