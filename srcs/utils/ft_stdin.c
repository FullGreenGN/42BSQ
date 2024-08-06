/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:25:53 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 16:34:38 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <bsq.h>

///////////////////////////////////////////////////////////////////
// read from stdin
int read_from_stdin(char *input, int buffer_size)
{
	char buffer[1024];
	int bytes_read;
	int total_bytes;

	total_bytes = 0;
	while ((bytes_read = read(0, buffer, 1024)) > 0)
	{
		if (total_bytes + bytes_read >= buffer_size)
			break;
		for (int i = 0; i < bytes_read; i++)
			input[total_bytes + i] = buffer[i];
		total_bytes += bytes_read;
	}
	return total_bytes;
}
///////////////////////////////////////////////////////////////////
// read from stdin and return as string
char *stdin_to_string(void)
{
	char *input;
	int total_bytes;
	int buffer_size;

	buffer_size = 1000000;
	input = (char *)malloc(buffer_size);
	if (!input)
		return ("");

	total_bytes = read_from_stdin(input, buffer_size);
	input[total_bytes] = '\0';

	return input;
}