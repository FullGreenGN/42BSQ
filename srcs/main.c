/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 14:29:22 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/bsq.h"

int main(int ac, char **av)
{
    char    *base_str;
	char	*end_str;
    char	**rmap;
	int		i;

    if (ac < 2)
    {
        write(2, "Usage: <file_path>\n", ft_strlen("Usage: %s <file_path>\n"));
        return (1);
    }
	i = 1;
	while (i < ac)
	{
		base_str = file_to_string(av[i]);
		rmap = process_map(base_str);
		end_str = malloc(ft_strlen(base_str) + 1);
		end_str = ft_strjoin(rmap);
		ft_putstr(end_str);
		ft_putstr("\n");
		i++;
	}
    return (0);
}
