/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:39:12 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 15:30:51 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

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
