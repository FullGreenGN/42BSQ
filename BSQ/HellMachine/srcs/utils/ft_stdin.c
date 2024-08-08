/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:25:53 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 18:29:52 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <bsq.h>

///////////////////////////////////////////////////////////////////
// func for add read
void	exec_func(int bytes_read, char *input, int *total_bytes, char *buffer)
{
	int		i;

	i = 0;
	while (i < bytes_read)
	{
		input[*total_bytes + i] = buffer[i];
		i++;
	}
	*total_bytes += bytes_read;
}

///////////////////////////////////////////////////////////////////
// read from stdin
int	read_from_stdin(char *input, int buffer_size)
{
	char	buffer[1024];
	int		bytes_read;
	int		total_bytes;

	total_bytes = 0;
	bytes_read = read(0, buffer, 1024);
	if (total_bytes + bytes_read >= buffer_size)
		return (total_bytes);
	exec_func(bytes_read, input, &total_bytes, buffer);
	while (bytes_read > 0)
	{
		bytes_read = read(0, buffer, 1024);
		if (total_bytes + bytes_read >= buffer_size)
			break ;
		exec_func(bytes_read, input, &total_bytes, buffer);
	}
	return (total_bytes);
}

///////////////////////////////////////////////////////////////////
// read from stdin and return as string
char	*stdin_to_string(void)
{
	char	*input;
	int		total_bytes;
	int		buffer_size;

	buffer_size = 1000000;
	input = malloc(buffer_size);
	if (!input)
		return ("");
	total_bytes = read_from_stdin(input, buffer_size);
	input[total_bytes] = '\0';
	return (input);
}
