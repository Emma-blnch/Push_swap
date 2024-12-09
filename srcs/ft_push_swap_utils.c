#include "../includes/ft_push_swap.h"

static int  check_overflow(long result, int sign, char next_digit)
{
    long    test;

    test = result * 10 + (next_digit - '0');
    if (sign == 1 && test > INT_MAX)
        return (1);
    if (sign == -1 && test < INT_MIN)
        return (1);
    return (0);
}

int	ft_atoi_safe(const char *str, int *is_valid)
{
	int		sign;
	long    result;

	sign = 1;
    *is_valid = 0;
    result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if ((*str++ == '-' || *str++ == '+'))
			return (0);
		if (*str == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
        if (check_overflow(result, sign, *str))
        {
            *is_valid = 1;
            return (0);
        }
		result = result * 10 + (*str++ - '0');
	}
	return ((int)result * sign);
}
