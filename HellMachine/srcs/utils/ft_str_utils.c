/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:28:02 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 14:23:09 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <bsq.h>

///////////////////////////////////////////////////////////////////
// write char c to stdout
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

///////////////////////////////////////////////////////////////////
// count size of string (in bytes)
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

///////////////////////////////////////////////////////////////////
// write string to stdout
void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

///////////////////////////////////////////////////////////////////
// convert str to int
int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

///////////////////////////////////////////////////////////////////
// copy src to dest
char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		dest_l;

	dest_l = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\n';
	return (dest);
}
