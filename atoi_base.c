/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:22:29 by shinckel          #+#    #+#             */
/*   Updated: 2023/02/06 12:23:03 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*There is no power operator in c. Because you can't use <math.h> in this exercise, build one function from scratch*/
int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= i;
		power--;
	}
	return (nb);
}

/*It is important to standardize lower and capital letters*/
char	to_lower(char c)
{
	if (c >= 65 && c <= 70)
		c += 32;
	return (c);
}

/*This will establish the  value for power*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*Each hex digit represents four binary digits(half a byte); therefore, hex is a language to write binary in an abbreviated form -> This means one byte can carry binary values from 0000 0000 to 1111 1111. In hex, these can be represented in a friendlier fashion, ranging from 00 to FF;
1A = (16ˆ1 * 1) + (16ˆ0 * 10) = 26;
*/
int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	result;
	int	power;

	i = 0;
	sign = 1;
	result = 0;
	power = ft_strlen((char *)str) - 1;
	if (str[i] == '-')
	{
		sign = -1;
		power -= 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result += ft_iterative_power(str_base, power) * (str[i] - 48);
		if (to_lower(str[i]) >= 'a' && to_lower(str[i]) <= 'f')
			result += ft_iterative_power(str_base, power) * (to_lower(str[i]) - 87);
		i++;
		power--;
	}
	return (result * sign);
}

int main(void)
{
	char *aux = "-FF";
	printf("%i\n", ft_atoi_base(aux, 16));
	return (0);
}

// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);