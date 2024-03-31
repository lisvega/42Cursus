/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisriver <lisriver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:47:39 by lisriver          #+#    #+#             */
/*   Updated: 2024/03/31 15:53:16 by lisriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinandfree(char *result, char *buffer)
{
	char	*line;

	line = ft_strjoin(result, buffer);
	free(result);
	return (line);
}

char	*read_file(int fd, char *result)
{
	int		byte_read;
	char	*buffer;

	if (!result)
		result = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
	{
		free(result);
		return (NULL);
	}
	while ((byte_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[byte_read] = '\0';
		result = joinandfree(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*liner(char *buffer)
{
	char	*new_line;
	int		len;

	len = 0;
	if (buffer[len] == 0)
		return (NULL);
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\n')
		len++;
	new_line = ft_substr(buffer, 0, len);
	return (new_line);
}

char *next_line(char *buffer)
{
    char *next;
    int i = 0;
    int j = 0;

    if (buffer == NULL)
        return NULL;

    // Buscar el siguiente carácter de nueva línea o el final del buffer
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;

    // Si no se encontró un carácter de nueva línea, liberar buffer y devolver NULL
    if (buffer[i] == '\0') {
        free(buffer);
        return NULL;
    }

    // Avanzar al inicio de la próxima línea
    i++;

    // Calcular la longitud de la próxima línea
    while (buffer[i + j] != '\n' && buffer[i + j] != '\0')
        j++;

    // Asignar memoria para la próxima línea
    next = ft_calloc((j + 1), sizeof(char)); // +1 para el carácter nulo terminador
    if (next == NULL) {
        free(buffer);
        return NULL;
    }

    // Copiar la próxima línea al nuevo buffer
    while (j > 0) {
        next[j - 1] = buffer[i + j - 1];
        j--;
    }
    next[j] = '\0'; // Agregar el carácter nulo terminador

    // Liberar el buffer original y devolver la próxima línea
    free(buffer);
    return next;
}


char	*get_next_line(int fd)
{
	static char	*result;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (result)
		{
			free(result);
			result = NULL;
		}
		return (NULL);
	}
	result = read_file(fd, result);
	if (!result)
		return (NULL);
	new_line = liner(result);
	if (new_line == NULL)
	{
		free(result);
		result = NULL;
	}
	result = next_line(result);
	return (new_line);
}

/* int main()
{
	int fd;
	char *result;
	int i;

	i = 0;
	fd = open("hola.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	result = get_next_line(fd);
	while (result != NULL)
	{
		printf("linea %d %s", i + 1, result);
		free(result);
		i++;
		result = get_next_line(fd);
	}

	close(fd);
	return (0);
} */
