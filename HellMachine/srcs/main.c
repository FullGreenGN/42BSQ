/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 18:14:24 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/bsq.h"

int	to_execute_main(char *base_str, t_args_data *data, char **rmap, char *e_str)
{
	if (base_str == NULL)
	{
		write(2, "map error\n", ft_strlen("map error\n"));
		return (1);
	}
	*data = string_args(base_str, (t_args_data){0});
	if (data->filler == 0)
	{
		write(2, "map error\n", ft_strlen("map error\n"));
		return (1);
	}
	rmap = process_map(base_str, *data);
	e_str = malloc(ft_strlen(base_str) + 1);
	e_str = ft_strjoin(rmap);
	ft_putstr(&e_str[4 + data->nb_lines_size]);
	return (0);
}

void	show_result(int i, int ac, char *end_str, t_args_data *data)
{
	ft_putstr(&end_str[4 + data->nb_lines_size]);
	if (i + 1 < ac)
		ft_putstr("\n");
}

int	main(int ac, char **av)
{
	t_args_data	data[1];
	char		*base_str;
	char		*end_str;
	char		**rmap;
	int			i;

	end_str = "";
	rmap = NULL;
	data->nb_lines_size = 0;
	if (ac < 2)
	{
		base_str = stdin_to_string();
		if (to_execute_main(base_str, data, rmap, end_str))
			return (1);
	}
	i = 1;
	while (i < ac)
	{
		base_str = file_to_string(av[i]);
		if (to_execute_main(base_str, data, rmap, end_str))
			return (1);
		show_result(i, ac, end_str, data);
		i++;
	}
	return (0);
}
