/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:30:55 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 22:54:50 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////
// return the minimum of 3 integers
int	min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		return (c);
	}
	else
	{
		if (b < c)
			return (b);
		return (c);
	}
}

void	ft_zero(char *buff, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      buff[i] = '\0';
      i = i + 1;
    }
}
