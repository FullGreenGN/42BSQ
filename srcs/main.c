/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 15:22:44 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int    ft_strlen(char *str);
char	*file_to_string(const char *file_path);
int	overwrite_file_with_string(const char *file_path, char *file_content);

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Usage: <file_path>\n", ft_strlen("Usage: %s <file_path>\n"));
        return (1);
    }

    
    char *str = file_to_string(av[1]);
    str[10] = 'B';
    overwrite_file_with_string(av[1], str);
    char *str2 = file_to_string(av[1]);
    printf("%s", str2);
    return (ac);
}