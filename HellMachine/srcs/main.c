/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:54:05 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 07:26:53 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/bsq.h"

char	*ft_realloc(char *buff, char *fullbuffer, int len)
{
  char	*new;
  int	i;
  int	compteur;

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
	char	buff[4096 + 1];
  	int		len;
  	char	*extend;
  	int		fd;
	t_args_data	data;

	ft_test_argv(ac);
	extend = NULL;
	ft_zero(buff, 4096);
	fd = open(av[1], O_RDONLY);
	ft_find_file(fd);
	while ((len = read(fd, buff, 4096)) > 0)
	{
		buff[len] = 0;
		extend = ft_realloc(buff, extend, len);
		data = (t_args_data){0};
		ft_zero(buff, 4096);
	}
	ft_test_read(len);
	ft_test_file(extend);
	to_execute_main(extend, &data, NULL, NULL);
	free(extend);
	close(fd);
	return (0);
}
