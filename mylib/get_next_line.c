/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:51:20 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 08:36:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

static char	*ft_read(int fd, char *reserve)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(reserve, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(reserve);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		reserve = ft_strjoin(reserve, buffer);
	}
	free(buffer);
	return (reserve);
}

static char	*ft_line(char *reserve)
{
	char	*line;
	int		i;

	i = 0;
	if (!reserve || !reserve[i])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_remain(char *reserve)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	remain = malloc(ft_strlen(reserve) - i + 1);
	if (!remain)
		return (NULL);
	i++;
	j = 0;
	while (reserve[i])
		remain[j++] = reserve[i++];
	remain[j] = '\0';
	free(reserve);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = ft_read(fd, reserve);
	if (!reserve)
		return (NULL);
	line = ft_line(reserve);
	reserve = ft_remain(reserve);
	return (line);
}
/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		ft_printf("%s", line);
	}
	close(fd);
} */
