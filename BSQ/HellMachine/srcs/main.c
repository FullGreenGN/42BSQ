/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 22:17:32 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <bsq.h>
#include <stdio.h>

///////////////////////////////////////////////////////////////////
// check map conformity
int	base_check(t_args_data *data, char *base_str)
{
	if (data->nb_lines == 0)
	{
		ft_putstr("map error");
		return (0);
	}
	if (!ft_check_map(base_str, *data))
	{
		ft_putstr("map error");
		return (0);
	}
	return (1);
}

///////////////////////////////////////////////////////////////////
// run prog
int	to_execute_main(char *base_str, t_args_data *data)
{
	int			i;
	char		**rmap;

	i = 1;
	if (base_str == NULL)
	{
		ft_putstr("map error");
		return (1);
	}
	*data = string_args(base_str, *data);
	if (!base_check(data, base_str))
		return (1);
	rmap = process_map(base_str, *data);
	while (rmap[i] != NULL)
	{
		ft_putstr(rmap[i]);
		ft_putchar('\n');
		i++;
	}
	if (rmap != NULL)
		clean_all(base_str, rmap);
	return (0);
}

///////////////////////////////////////////////////////////////////
// main of tool
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
		to_execute_main(base_str, data);
		if (i + 1 < ac)
			ft_putstr("\n");
		i++;
	}
	return (0);
}
