/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segfault.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:51:01 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 07:20:59 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <bsq.h>

void	ft_test_argv(int argc)
{
    if (argc != 2)
    {
      write(2, "./bsq [map(s)]\n", 13);
      exit(84);
    }
}

void	ft_find_file(int fd)
{
    if (fd == -1)
    {
        write(2, "File(s) not found\n", 21);
        write(2, "./bsq [map(s)]\n", 13);
        exit(84);
    }
}

void	ft_test_file(char *tab)
{
    if (tab == NULL)
    {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map(s)]\n", 13);
        exit(84);
    }
}

void	ft_test_char(char c)
{
    if (c != '.' && c != 'o' && c != '\n' && c != '\0')
    {
        write(2, "Invalid File\n", 16);
        write(2, "./bsq [maps(s)]\n", 13);
        exit(84);
    }
}

void	ft_test_read(int read)
{
    if (read == -1)
    {
        write(2, "File only\n", 11);
        exit(84);
    }
}

void	ft_empty_file(char c)
{
  if (c == '\0')
    {
        write(2, "Empty File\n", 16);
        write(2, "./bsq [map(s)]\n", 13);
        exit(84);
    }
}
