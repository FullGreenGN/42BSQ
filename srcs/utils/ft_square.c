/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:36:27 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/05 18:08:38 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"

char	**ft_split(char *str, char *charset);
int		nb_word(char *str, char *charset);
int		ft_atoi(const char *str);

///////////////////////////////////////////////////////////////////
// create a square of x * y with char c
char **ft_square(char **map, int x, int y, char c)
{
	int i;
	int j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			map[i][j] = c;
			j++;
		}
		i++;
	}
	return (map);
}

///////////////////////////////////////////////////////////////////
// scrap 4 arguments at the start of a string
t_args_data    string_args(char *str, t_args_data data)
{
	int i;

	data.nb_lines = ft_atoi(str);
	i = 0;
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	data.empty = str[i];
	i++;
	data.obstacle = str[i];
	i++;
	data.filler = str[i];
	return (data);
}