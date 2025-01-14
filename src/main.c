/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:52:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 20:32:09 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	*free_split(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	cleanup_and_exit(t_stack **a, t_stack **b, char **arv, int flag)
{
	if (flag)
		free_split(arv);
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	return (1);
}

static char	*join_args(char **av, int ac)
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

static int	handle_args(char **av, int ac, char ***arv, int *split_flag)
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**arv;
	int		split_flag;

	a = NULL;
	b = NULL;
	split_flag = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		if (ac == 2 && !av[1][0])
			write(2, "Error\n", 6);
		return (1);
	}
	if (handle_args(av, ac, &arv, &split_flag))
		return (1);
	if (init_stack(&a, arv) != 0)
		return (cleanup_and_exit(&a, &b, arv, split_flag));
	if (split_flag)
		free_split(arv);
	if (!is_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
}
