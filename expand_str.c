/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:38:31 by shinckel          #+#    #+#             */
/*   Updated: 2023/01/30 20:54:05 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_no_breaks(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == 9 || str[j] == 32)
			i = 1;
		j++;
	}
	return (i);
}

int	test_end_line(char *str, int pos)
{
	int	i;

	i = 0;
	while (str[pos])
	{
		if (str[pos] != 9 && str[pos] != 32)
			i = 1;
		pos++;
	}
	return (i);
}

void	expand_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (test_no_breaks(str) == 0)
			break ;
		if (i > 0 && (str[i] == 9 || str[i] == 32))
		{
			if (test_end_line(str, i) == 0)
				break ;
			if (str[i - 1] != 9 && str[i - 1] != 32)
				write(1, "   ", 3);
		}
		if (str[i] >= 33 && str[i] <= 126)
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}

// Write a program that takes a string and displays it with exactly three spaces
// between each word, with no spaces or tabs either at the beginning or the end,
// followed by a newline.

// A word is a section of string delimited either by spaces/tabs, or by the
// start/end of the string.

// If the number of parameters is not 1, or if there are no words, simply display
// a newline.
 
// Examples:

// $> ./expand_str "See? It's easy to print the same thing" | cat -e
// See?   It's   easy   to   print   the   same   thing$
// $> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./expand_str "" | cat -e
// $
// $>

// $> ./expand_str " seulement          la c'est      plus dur " | cat -e
// seulement   la   c'est   plus   dur$
// $> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
// $
// $> ./expand_str "" | cat -e
// $
// $>