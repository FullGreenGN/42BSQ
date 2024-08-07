/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 08:26:54 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/bsq.h"

char	*ft_realloc(char *buff, char *fullbuffer, int len)
{
  char		*new;
  int		i;
  int		compteur;

  compteur = 0;
  i = 0;
  new = malloc(sizeof(*new) * (ft_strlen(fullbuffer) + len + 1));
  if (new == NULL)
	exit(84);
  while (fullbuffer != NULL && fullbuffer[i] != '\0')
	{
	  new[i] = fullbuffer[i];
	  i = i + 1 ;
	}
  free(fullbuffer);
  while (buff[compteur] != '\0')
	{
	  new[i] = buff[compteur];
	  i = i + 1;
	  compteur = compteur + 1;
	}
  new[i] = '\0';
  return (new);
}

void	ft_test_argv(int argc)
{
	if (argc != 2)
	{
		write(2, "./bsq [map(s)]\n", 13);
		exit(84);
	}
}

int	main(int ac, char **av)
{
	char	buff[4096 + 1];
	int		len;
	char	*extend;
	int		fd;

	ft_test_argv(ac);
	extend = NULL;
	ft_zero(buff, 4096);
	fd = open(av[1], O_RDONLY);
	ft_find_file(fd);
	while ((len = read(fd, buff, 4096)) > 0)
	{
		buff[len] = 0;
		extend = ft_realloc(buff, extend, len);
		ft_zero(buff, 4096);
	}
	ft_test_read(len);
	ft_test_file(extend);
	ft_create_tab(extend);
	free(extend);
	close(fd);
	return (0);
}
