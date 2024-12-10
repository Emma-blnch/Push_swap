#include "../includes/ft_push_swap.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	handle_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	check_invalid_end(const char *str)
{
	while (*str)
	{
		if (!is_whitespace(*str))
			return (1); // Contient des caractères non valides
		str++;
	}
	return (0); // Tout va bien
}

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
	long	result;

	*is_valid = 1; // Par défaut, on assume l'entrée invalide
	result = 0;
	while (is_whitespace(*str))
		str++;
	sign = handle_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		if (check_overflow(result, sign, *str))
			return (0);
		result = result * 10 + (*str++ - '0');
	}
	if (check_invalid_end(str)) // Vérifie s'il reste des caractères invalides
		return (0);
	*is_valid = 0; // Tout est correct
	return ((int)(result * sign));
}
