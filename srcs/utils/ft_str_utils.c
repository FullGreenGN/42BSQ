/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:28:02 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 15:43:57 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

///////////////////////////////////////////////////////////////////
// write char c to stdout
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

///////////////////////////////////////////////////////////////////
// count size of string (in bytes)
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

///////////////////////////////////////////////////////////////////
// write string to stdout
void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

///////////////////////////////////////////////////////////////////
// compare two strings
int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	char	diff;
	i = 0;
	diff = 0;
	while (s1[i] && s2[i])
	{
		diff = s1[i] - s2[i];
		i++;
		if (diff != 0)
			return (diff);
	}
	diff = s1[i] - s2[i];
	return (diff);
}
