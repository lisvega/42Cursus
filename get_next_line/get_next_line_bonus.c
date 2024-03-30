/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisriver <lisriver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:38:53 by lisriver          #+#    #+#             */
/*   Updated: 2024/03/30 12:01:32 by lisriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*joinandfree(char *result, char *buffer)
{
	char	*line;

	line = ft_strjoin(result, buffer);
	free(result);
	return (line);
}

static char	*read_file(int fd, char *result)
{
	int		byte_read;
	char	*buffer;

	if (!result)
		result = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		result = joinandfree(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

static char	*liner(char *buffer)
{
	char	*new_line;
	int		len;

	len = 0;
	if (buffer[len] == 0)
		return (NULL);
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	len++;
	new_line = ft_substr(buffer, 0, len);
	return (new_line);
}

static char	*next_line(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*result[1024];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (result[fd])
		{
			free(result[fd]);
			result[fd] = NULL;
		}
		return (NULL);
	}
	result[fd] = read_file(fd, result[fd]);
	if (!result[fd])
		return (free(result[fd]), NULL);
	new_line = liner(result[fd]);
	result[fd] = next_line(result[fd]);
	return (new_line);
}
