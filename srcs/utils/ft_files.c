/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:01:53 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/06 14:23:03 by fullgreen        ###   ########.fr       */
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
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		total_bytes += bytes_read;
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

///////////////////////////////////////////////////////////////////
// write content to file_path
int	write_to_file(const char *file_path, const char *content)
{
	int		fd;
	int		bytes_written;
	int		content_length;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	content_length = ft_strlen((char *)content);
	bytes_written = write(fd, content, content_length);
	close(fd);
	if (bytes_written != content_length)
		return (-1);
	return (0);
}

///////////////////////////////////////////////////////////////////
// overwrite file with its own content
int	overwrite_file_with_string(const char *file_path, char *file_content)
{
	int		result;

	if (file_content == NULL)
		return (-1);
	result = write_to_file(file_path, file_content);
	free(file_content);
	return (result);
}
