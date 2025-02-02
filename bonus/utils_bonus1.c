/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:27 by hbousset          #+#    #+#             */
/*   Updated: 2025/02/02 16:17:05 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	cleanup_and_exit(t_stack **a, t_stack **b, char **arv, int flag)
{
	if (flag)
		free_split(arv);
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	return (1);
}

char	*join_args(char **av, int ac)
{
	int		total_len;
	char	*joined;
	int		i;
	int		pos;

	total_len = 0;
	i = 0;
	pos = 0;
	while (++i < ac)
		total_len += ft_strlen(av[i]) + 1;
	joined = malloc(total_len);
	if (!joined)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		ft_strcpy(joined + pos, av[i]);
		pos += ft_strlen(av[i]);
		if (i < ac - 1)
			joined[pos++] = ' ';
		i++;
	}
	joined[pos] = '\0';
	return (joined);
}

int	handle_args(char **av, int ac, char ***arv, int *split_flag)
{
	char	*joined;

	joined = join_args(av, ac);
	if (!joined)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	*arv = ft_split(joined, 32);
	free(joined);
	*split_flag = 1;
	if (!*arv)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	cleanup(t_stack **a, t_stack **b, char *line)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	if (line)
		free(line);
	exit (1);
}

char	*get_next(int fd)
{
	char	line[80000];
	int		readbyte;
	char	buff;
	int		i;

	readbyte = 1;
	i = 0;
	buff = 0;
	line[i] = 0;
	while (readbyte)
	{
		readbyte = read(fd, &buff, 1);
		if (readbyte <= 0)
			break ;
		line[i++] = buff;
		line[i] = 0;
		if (buff == '\n')
			break ;
	}
	if (!*line)
		return (NULL);
	return (ft_strdup(line));
}
