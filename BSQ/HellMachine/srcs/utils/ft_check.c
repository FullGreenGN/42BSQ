/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:53:14 by yseguin           #+#    #+#             */
/*   Updated: 2024/08/07 22:11:52 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>
#include <stdlib.h>
#include <stdio.h>

///////////////////////////////////////////////////////////////////
// malloc charset 
char	*ft_charset(t_args_data data)
{
	char	*charset;

	charset = malloc(sizeof(char) * 4);
	charset[0] = data.empty;
	charset[1] = data.obstacle;
	charset[2] = data.filler;
	charset[3] = '\n';
	return (charset);
}

///////////////////////////////////////////////////////////////////
// check part 2
int	check2(int *i, int *j, t_args_data data, char *str)
{
	char	*charset;

	charset = ft_charset(data);
	while (str[*i])
	{
		if (!ft_contain(charset, str[*i]))
			return (free(charset), 0);
		if (str[*i] == '\n')
			(*j)++;
		(*i)++;
	}
	return (free(charset), 1);
}

///////////////////////////////////////////////////////////////////
// check part 1 and main
int	ft_check_map(char *str, t_args_data data)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		if (str[i] == '\n' && str[i - 1] == '\n')
			return (0);
		i++;
	}
	i = data.nb_lines_size + 4;
	j = 0;
	if (!check2(&i, &j, data, str))
		return (0);
	if (j < data.nb_lines)
		return (0);
	if (j != data.nb_lines)
		return (0);
	if ((i - data.nb_lines_size - 4 - j) != data.nb_lines * data.nb_lines)
		return (0);
	return (1);
}
