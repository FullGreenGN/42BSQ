/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:28:02 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/05 17:37:48 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
// compare two strings with n bytes
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
        int diff = (unsigned char)s1[i] - (unsigned char)s2[i];
        if (diff != 0 || s1[i] == '\0')
            return diff;
		i++;
    }
    return 0;
}
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
