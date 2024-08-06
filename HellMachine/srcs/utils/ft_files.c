/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:01:53 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/06 16:32:10 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <bsq.h>

///////////////////////////////////////////////////////////////////
// count size of file_path (in bytes)
int	file_size(const char *file_path)
{
	int		bytes_read;
	int		fd;
	int		total_bytes;
	char	buffer[1];

	total_bytes = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		total_bytes += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (total_bytes);
}

///////////////////////////////////////////////////////////////////
// use open and read for convert dico into str file
char	*file_to_string(const char *file_path)
{
	int		fd;
	char	*file_content;
	int		size;

	size = file_size(file_path);
	if (size == -1)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = malloc(size + 1);
	if (file_content == NULL)
	{
		close(fd);
		return (NULL);
	}
	if (read(fd, file_content, size) != size)
	{
		free(file_content);
		close(fd);
		return (NULL);
	}
	file_content[size] = '\0';
	close(fd);
	return (file_content);
}
