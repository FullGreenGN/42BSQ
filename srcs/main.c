/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 16:21:38 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/bsq.h"

int main(int ac, char **av)
{
	t_args_data	data;
    char		*base_str;
	char		*end_str;
    char		**rmap;
	int			i;

    if (ac < 2)
    {
        write(2, "Usage: <file_path>\n", ft_strlen("Usage: %s <file_path>\n"));
        return (1);
    }
	i = 1;
	while (i < ac)
	{
		base_str = file_to_string(av[i]);
		if (base_str == NULL)
		{
			write(2, "map error\n", ft_strlen("map error\n"));
			return (1);
		}
		data = string_args(base_str, (t_args_data){0});
		if (data.filler == 0)
		{
			write(2, "map error\n", ft_strlen("map error\n"));
			return (1);
		}
		rmap = process_map(base_str, data);
		end_str = malloc(ft_strlen(base_str) + 1);
		end_str = ft_strjoin(rmap);
		ft_putstr(&end_str[4 + data.nb_lines_size]);
		if (i + 1 < ac)
			ft_putstr("\n");
		i++;
	}
    return (0);
}
