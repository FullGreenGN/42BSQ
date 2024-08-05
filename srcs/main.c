/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 18:06:33 by seguinyanni      ###   ########.fr       */
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

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Usage: <file_path>\n", ft_strlen("Usage: %s <file_path>\n"));
        return (1);
    }

    char *str = file_to_string(av[1]);
    //char **tab = ft_split(&str[5], "\n");
    printf("str: %s\n", str);
    t_args_data data = {0};
    data = string_args(str, data);
    printf("nb_lines: %d\n", data.nb_lines);
    return (ac);
}