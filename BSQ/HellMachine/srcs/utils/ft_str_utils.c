/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:28:02 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 21:57:59 by yseguin          ###   ########.fr       */
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
int	ft_atoi(const char *str, int n)
{
	int	res;
	int	negative;
	int	i;

	i = 0;
	negative = 1;
	res = 0;
	while (i < n && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		++i;
	if (i < n && str[i] == '-')
		negative = -1;
	if (i < n && (str[i] == '-' || str[i] == '+'))
		++i;
	while (i < n && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		++i;
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
