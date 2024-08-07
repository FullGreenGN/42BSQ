/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:14:11 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 08:37:27 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

///////////////////////////////////////////////////////////////////
// count size of string (in bytes) until '\n'
int	ft_strlenbn(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i] != '\n')
	{
		i = i + 1;
		a = a + 1;
	}
	i = i + 1;
	a = a + 1;
	while (str[i] != '\n' && str[i] != '\0')
		i = i + 1;
	return (i - a);
}
///////////////////////////////////////////////////////////////////
// count number of '\n' in string
int	ft_strnbline(char *str)
{
	int	i;
	int	save;

	save = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			save = save + 1;
		i = i + 1;
	}
	if (str[i - 1] == '\n')
		save = save - 1;
	return (save);
}
