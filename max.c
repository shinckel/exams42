/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:45:20 by shinckel          #+#    #+#             */
/*   Updated: 2023/01/30 20:45:21 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	largest;
	int	i;

	largest = tab[0];
	i = 1;
	while (i < len)
	{
		if (largest < tab[i])
			largest = tab[i];
		i++;
	}
	return (largest);
}

// int main(void)
// {
// 	int tab[5] = {4, 5, 3, 1};
// 	printf("%i", max(tab, 4));
// 	return (0);
// }

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.