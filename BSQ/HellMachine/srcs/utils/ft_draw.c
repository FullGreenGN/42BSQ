/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:39:12 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 15:53:02 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

///////////////////////////////////////////////////////////////////
// fill the lines with the filler character
void	fill_lines(char **lines, t_args_data data, t_map_data *map)
{
	int		i;
	int		j;

	i = map->max_i;
	while (i > map->max_i - map->max_size)
	{
		j = map->max_j;
		while (j > map->max_j - map->max_size)
		{
			lines[i + 1][j] = data.filler;
			j--;
		}
		i--;
	}
}

///////////////////////////////////////////////////////////////////
// split of fill_dp for nom
void	to_execute(int **dp, int i, int j, t_map_data *map)
{
	if (i == 0 || j == 0)
		dp[i][j] = 1;
	else
	{
		dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
		dp[i][j] += 1;
	}
	if (dp[i][j] > map->max_size)
	{
		map->max_size = dp[i][j];
		map->max_i = i;
		map->max_j = j;
	}
}

///////////////////////////////////////////////////////////////////
// fill the 2D array with the size of the biggest square
void	fill_dp(int **dp, char **lines, t_args_data data, t_map_data *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.nb_lines)
	{
		j = 0;
		while (j < ft_strlen(lines[1]))
		{
			if (lines[i + 1][j] == data.empty)
				to_execute(dp, i, j, map);
			else
				dp[i][j] = 0;
			j++;
		}
		i++;
	}
}
