/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:30:22 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 08:35:00 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////
void	ft_create_tab(char *buff)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(*tab) * (ft_strnbline(buff) + 1));
	if (tab == NULL)
		exit(84);
	while (i < ft_strnbline(buff))
	{
		tab[i] = malloc(sizeof(tab) * (ft_strlenbn(buff) + 1));
		if (tab[i] == NULL)
			exit(84);
		i = i + 1;
	}
	ft_bufftotab(buff, tab, 0, 0);
	redirect(tab, ft_strnbline(buff) - 1,ft_strlenbn(buff) - 1);
}