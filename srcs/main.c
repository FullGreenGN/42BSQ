/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 15:16:31 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*file_to_string(const char *file_path);
int	overwrite_file_with_string(const char *file_path, char *file_content);

int main(int ac, char **av)
{
    char *str = file_to_string(av[1]);
    str[10] = 'B';
    overwrite_file_with_string(av[1], str);
    char *str2 = file_to_string(av[1]);
    printf("%s", str2);
    return (ac);
}