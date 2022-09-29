/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:45:46 by dfanucch          #+#    #+#             */
/*   Updated: 2022/09/25 12:45:47 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int s1_len)
{
	char	*result;
	size_t	result_len;
	size_t	s2_len;

	s2_len = ft_strlen(s2);
	result_len = (size_t)s1_len + s2_len;
	result = malloc((result_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = 0;
	return (result - result_len);
}

char	*get_buffer(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (*buffer == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes || bytes == -1)
			return (NULL);
		buffer[bytes] = 0;
	}
	return (buffer);
}

char	*read_buffer(char *buffer)
{
	char	*readed;
	char	*tmp;
	char	*buffer_trav;
	size_t	len;

	readed = NULL;
	buffer_trav = buffer;
	len = 0;
	while (*buffer_trav)
	{
		tmp = readed;
		readed = ft_calloc(len + 2, sizeof(char));
		if (len == 0)
		{
			readed[0] = *buffer_trav++;
			len++;
			continue ;
		}
		ft_memcpy(readed, tmp, len);
		readed[len++] = *buffer_trav++;
		free(tmp);
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	char	*readed;
	char	*tmp;

	buffer = get_buffer(fd);
	line = NULL;
	int i = 0;
	while (buffer != NULL)
	{
		if (line == NULL)
			line = ft_strdup("");
		readed = read_buffer(buffer);
		tmp = line;
		line = ft_strjoin(tmp, readed, i);
		i += ft_strlen(readed);
		free(tmp);
		free(readed);
		if (line[i - 1] == '\n')
			return (line);
		buffer = get_buffer(fd);
	}
	return (line);
}
