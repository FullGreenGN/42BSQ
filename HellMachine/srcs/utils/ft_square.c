/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:36:27 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/06 17:51:39 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <bsq.h>

///////////////////////////////////////////////////////////////////
// create a square of x * y with char c
char	**ft_square(char **map, int x, int y, char c)
{
	int	i;
	int	j;

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
t_args_data	string_args(char *str, t_args_data data)
{
	int	i;

	data.nb_lines = ft_atoi(str);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	data.nb_lines_size = i;
	if (str[i] == '\0')
		return (data = (t_args_data){0});
	data.empty = str[i];
	i++;
	if (str[i] == '\0' || data.empty == str[i])
		return (data = (t_args_data){0});
	data.obstacle = str[i];
	i++;
	if (str[i] == '\0' || data.empty == str[i] || data.obstacle == str[i])
		return (data = (t_args_data){0});
	data.filler = str[i];
	return (data);
}

///////////////////////////////////////////////////////////////////
// initialize a 2D array of integers
int	**initialize_dp(int nb_lines, int cols)
{
	int	**dp;
	int	i;

	dp = (int **)malloc(nb_lines * sizeof(int *));
	i = 0;
	while (i < nb_lines)
	{
		dp[i] = (int *)malloc(cols * sizeof(int));
		i++;
	}
	return (dp);
}

///////////////////////////////////////////////////////////////////
// process the map and return the filled map
char	**process_map(char *str, t_args_data data)
{
	char		**lines;
	int			cols;
	int			**dp;
	t_map_data	map_data;

	lines = ft_split(str, "\n");
	cols = ft_strlen(lines[1]);
	dp = initialize_dp(data.nb_lines, cols);
	map_data.max_size = 0;
	map_data.max_i = 0;
	map_data.max_j = 0;
	fill_dp(dp, lines, data, &map_data);
	fill_lines(lines, data, &map_data);
	return (lines);
}
