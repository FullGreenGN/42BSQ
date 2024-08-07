/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:39:12 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 08:30:40 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <bsq.h>

void	ft_bufftotab(char *buff, char **tab, int a, int b)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i = i + 1;
	i = i + 1;
	ft_empty_file(buff[i + 1]);
	while (buff[i] != '\0')
	{
		ft_test_char(buff[i]);
		if (buff[i] == '\n' || buff[i] == '\0')
		{
			tab[a][b] = '\0';
			a = a + 1;
			b = 0;
		}
		else
		{
			tab[a][b] = buff[i];
			b = b + 1;
		}
		i = i + 1;
	}
}

///////////////////////////////////////////////////////////////////
// Find the biggest square in the map and replace it with 'x'
int	test_tab(int tmp, char **tab, int width, int lenght)
{
	int	i;

	i = 1;
	if (tab[lenght][width] != '.')
		return (0);
	while (i < tmp)
	{
		if (tab[lenght][width + i] != '.' || tab[lenght + i][width] != '.')
			return (0);
		i = i + 1;
	}
	return (1);
}

///////////////////////////////////////////////////////////////////
// Find the biggest square in the map and replace it with 'x'
void	ft_remp_tab(char **tab, int posx, int posy, int count)
{
	int	i;
	int	save;
	int	a;

	a = 0;
	save = count - 1;
	i = count - 1;
	while (i > 0)
	{
		while (save > 0)
		{
			tab[posx][posy - a] = 'x';
			a = a + 1;
			save = save - 1;
		}
		save = count - 1;
		a = 0;
		posx = posx - 1;
		i = i - 1;
	}
}

///////////////////////////////////////////////////////////////////
// Find the biggest square in the map and replace it with 'x'
int	ft_remp_tab1(char **tab)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (tab[a][b] != 0)
	{
		if (tab[a][b] == '.')
		{
			tab[a][b] = 'x';
			return (0);
		}
		else if (tab[a][b] == 'o')
			b = b + 1;
		else
		{
			b = 0;
			a = a + 1;
		}
	}
	return (0);
}

///////////////////////////////////////////////////////////////////
void	ft_search2(char **tab, int *lenght, int *width, t_bsq *bsq)
{
	bsq->tmpwidth = *width;
	bsq->tmplenght = *lenght;
	bsq->tmp = 1;
	while (*lenght >= 0 && *width >= 0 && test_tab(bsq->tmp, tab, *width,
													*lenght) == 1)
	{
		*lenght = *lenght - 1;
		*width = *width - 1;
		bsq->tmp = bsq->tmp + 1;
	}
	if (bsq->tmp >= bsq->count)
	{
		bsq->count = bsq->tmp;
		bsq->posx = *lenght + bsq->count - 1;
		bsq->posy = *width + bsq->count - 1;
	}
	*width = bsq->tmpwidth;
	*lenght = bsq->tmplenght;
	*width = *width - 1;
}

///////////////////////////////////////////////////////////////////
void	ft_search(char **tab, int *lenght, int *width, t_bsq *bsq)
{
	if (tab[*lenght][*width] == 'o' && *width != 0)
		*width = *width - 1;
	else if (*width == 0)
	{
		*lenght = *lenght - 1;
		*width = bsq->wid;
	}
	else if (tab[*lenght][*width] == '.')
		ft_search2(tab, lenght, width, bsq);
	bsq->i = bsq->i + 1;
}

///////////////////////////////////////////////////////////////////
void	redirect(char **tab, int lenght, int width)
{
	t_bsq	bsq;

	bsq.len = lenght;
	bsq.wid = width;
	bsq.count = 0;
	bsq.tmp = 0;
	bsq.i = 0;
	while (bsq.i < (bsq.len + 1) * (bsq.wid + 1))
		ft_search(tab, &lenght, &width, &bsq);
	if (bsq.count > 2)
		ft_remp_tab(tab, bsq.posx, bsq.posy, bsq.count);
	else
		ft_remp_tab1(tab);
	bsq.i = 0;
	while (bsq.i <= bsq.len)
	{
		ft_putstr(tab[bsq.i]);
		ft_putchar('\n');
		bsq.i = bsq.i + 1;
	}
}
