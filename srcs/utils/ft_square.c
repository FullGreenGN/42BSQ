/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:36:27 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/06 14:21:19 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../includes/bsq.h"

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
	data.empty = str[i];
	i++;
	data.obstacle = str[i];
	i++;
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
// fill the 2D array with the size of the biggest square
void	fill_dp(int **dp, char **lines, t_args_data data, int *max_size, int *max_i, int *max_j)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.nb_lines)
	{
		j = 0;
		while (j < ft_strlen(lines[1]))
		{
			if (lines[i + 1][j] == data.empty)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				if (dp[i][j] > *max_size)
				{
					*max_size = dp[i][j];
					*max_i = i;
					*max_j = j;
				}
			}
			else
				dp[i][j] = 0;
			j++;
		}
		i++;
	}
}

///////////////////////////////////////////////////////////////////
// fill the lines with the filler character
void	fill_lines(char **lines, t_args_data data, int max_size, int max_i, int max_j)
{
	int	i;
	int	j;

	i = max_i;
	while (i > max_i - max_size)
	{
		j = max_j;
		while (j > max_j - max_size)
		{
			lines[i + 1][j] = data.filler;
			j--;
		}
		i--;
	}
}

///////////////////////////////////////////////////////////////////
// process the map and return the filled map
char	**process_map(char *map)
{
	t_args_data	data;
	char		**lines;
	int			cols;
	int			**dp;
	int			max_size;
	int			max_i;
	int			max_j;

	data = string_args(map, (t_args_data){0});
	lines = ft_split(map, "\n");
	cols = ft_strlen(lines[1]);
	dp = initialize_dp(data.nb_lines, cols);
	max_size = 0;
	max_i = 0;
	max_j = 0;
	fill_dp(dp, lines, data, &max_size, &max_i, &max_j);
	fill_lines(lines, data, max_size, max_i, max_j);
	return (lines);
}
