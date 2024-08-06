/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:36:27 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/06 12:19:11 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../includes/bsq.h"

#define BUF_SIZE 4096

char	**ft_split(char *str, char *charset);
int		nb_word(char *str, char *charset);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);

///////////////////////////////////////////////////////////////////
// create a square of x * y with char c
char	**ft_square(char **map, int x, int y, char c)
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

static int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

char	**process_map(char *map) {
    t_args_data data = string_args(map, (t_args_data){0});
    char **lines = ft_split(map, "\n");

    // Calculate the number of columns
    int cols = ft_strlen(lines[1]);

    // Allocate DP array
    int **dp = (int **)malloc(data.nb_lines * sizeof(int *));
    for (int i = 0; i < data.nb_lines; i++) {
        dp[i] = (int *)malloc(cols * sizeof(int));
    }

    int max_size = 0;
    int max_i = 0;
    int max_j = 0;

    // Fill the DP array
    for (int i = 0; i < data.nb_lines; i++) {
        for (int j = 0; j < cols; j++) {
            if (lines[i + 1][j] == data.empty) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_i = i;
                    max_j = j;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Replace the empty characters with the full character in the largest square
    for (int i = max_i; i > max_i - max_size; i--) {
        for (int j = max_j; j > max_j - max_size; j--) {
            lines[i + 1][j] = data.filler;
        }
    }
	return (lines);
}
