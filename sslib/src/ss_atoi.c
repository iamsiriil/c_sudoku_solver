#include "../inc/sslib.h"

int	ss_atoi(const char *str)
{
	int	nbr;
	int	sign;

	while (ss_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+') {
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nbr = 0;
	while (ss_isdigit(*str)) {
		nbr = nbr * 10 + (*str - 48);
		str++;
	}

	return (nbr * sign);
}
