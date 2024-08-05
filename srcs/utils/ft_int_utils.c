/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:41:00 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 15:43:55 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////
//  swap two int values
void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}