/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:29:08 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 14:55:47 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    ft_strlen(char *str);

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}