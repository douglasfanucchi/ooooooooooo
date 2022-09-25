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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	result_len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result_len = s1_len + s2_len;
	result = malloc((result_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = 0;
	free(s1 - s1_len);
	free(s2 - s2_len);
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

char	ft_isline(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char	*read_buffer(char *buffer)
{
	char	*jumpline;
	char	*str;

	str = NULL;
	jumpline = ft_strchr(buffer, '\n');
	if (jumpline)
	{
		str = ft_substr(buffer, 0, jumpline - buffer + 1);
		ft_memcpy(buffer, (jumpline + 1), ft_strlen(jumpline + 1) + 1);
		return (str);
	}
	str = ft_strdup(buffer);
	*buffer = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	if (BUFFER_SIZE < 0)
		return (NULL);
	buffer = get_buffer(fd);
	line = NULL;
	while (buffer != NULL)
	{
		if (line == NULL)
			line = ft_strdup("");
		line = ft_strjoin(line, read_buffer(buffer));
		if (ft_strchr(line, '\n'))
			return (line);
		buffer = get_buffer(fd);
	}
	return (line);
}
