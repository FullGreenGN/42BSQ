/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:13:05 by yseguin           #+#    #+#             */
/*   Updated: 2024/08/07 11:38:41 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

///////////////////////////////////////////////////////////////////
// clean an str malloc
void	clean_str(char *str)
{
	free(str);
}

///////////////////////////////////////////////////////////////////
// clean a tab of str malloc
void	clean_str_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

///////////////////////////////////////////////////////////////////
// clean  a tab of int malloc
void	clean_dp(int **dp, int cols)
{
	int		i;

	i = 0;
	while (i < cols)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

///////////////////////////////////////////////////////////////////
// clean all main malloc
void	free_all(char *b_str, char **tab)
{
	clean_str(b_str);
	clean_str_tab(tab);
}
