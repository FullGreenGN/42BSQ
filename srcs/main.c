/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 12:08:51 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/bsq.h"

int				ft_strlen(char *str);
char			*file_to_string(const char *file_path);
char			**ft_split(char *str, char *charset);
int				overwrite_file_with_string(const char *file_path, char *file_content);
t_args_data		string_args(char *strn, t_args_data data);
char            **process_map(char *map);

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Usage: <file_path>\n", ft_strlen("Usage: %s <file_path>\n"));
        return (1);
    }
    char **map = process_map(file_to_string(av[1]));
    for (int i = 0; map[i]; i++)
    {
        printf("%s\n", map[i]);
    }
    return (ac);
}