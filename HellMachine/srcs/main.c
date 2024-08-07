/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 11:36:08 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsq.h>

int	to_execute_main(char *base_str, t_args_data *data)
{
	int			i;
	char		**rmap;

	i = 1;
	rmap = NULL;
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
	while (rmap[i] != NULL)
	{
		ft_putstr(rmap[i]);
		ft_putchar('\n');
		i++;
	}
	free_all(base_str, rmap);
	return (0);
}

int	main(int ac, char **av)
{
	t_args_data	data[1];
	char		*base_str;
	int			i;

	base_str = "";
	data->nb_lines_size = 0;
	if (ac < 2)
	{
		base_str = stdin_to_string();
		if (to_execute_main(base_str, data))
			return (1);
	}
	i = 1;
	while (i < ac)
	{
		base_str = file_to_string(av[i]);
		if (to_execute_main(base_str, data))
			return (1);
		if (i + 1 < ac)
			ft_putstr("\n");
		i++;
	}
	return (0);
}
