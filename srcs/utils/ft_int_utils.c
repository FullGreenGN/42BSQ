/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:30:55 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 12:44:23 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////
// return the minimum of 3 integers
int min(int a, int b, int c)
{
	if (a < b) {
		return (a < c) ? a : c;
	} else {
		return (b < c) ? b : c;
	}
}