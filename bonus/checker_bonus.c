/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:20:15 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/15 13:33:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	do_double_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "rr"))
	{
		a = rotate(a);
		b = rotate(b);
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		a = r_rotate(a);
		b = r_rotate(b);
	}
	else if (!ft_strcmp(line, "ss"))
	{
		a = swap(a);
		b = swap(b);
	}
	else
		cleanup(a, b, line);
}

void	do_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "pa"))
		push(a, b);
	else if (!ft_strcmp(line, "pb"))
		push(b, a);
	else if (!ft_strcmp(line, "ra"))
		a = rotate(a);
	else if (!ft_strcmp(line, "rb"))
		b = rotate(b);
	else if (!ft_strcmp(line, "rra"))
		a = r_rotate(a);
	else if (!ft_strcmp(line, "rrb"))
		b = r_rotate(b);
	else if (!ft_strcmp(line, "sa"))
		a = swap(a);
	else if (!ft_strcmp(line, "sb"))
		b = swap(b);
	else
		do_double_command(a, b, line);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next(0);
	while (line)
	{
		do_command(a, b, line);
		free(line);
		line = get_next(0);
	}
	if (is_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static int	validate_and_init(int ac, char **av, t_stack **a, t_stack **b)
{
	char	**arv;
	int		split_flag;
	int		i;

	split_flag = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		if (ac == 2 && !av[1][0])
			write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (++i < ac)
	{
		if (!av[i] || !av[i][0] || !skip_whitespace(av[i]))
			return (write(2, "Error\n", 6), 1);
	}
	if (handle_args(av, ac, &arv, &split_flag))
		return (1);
	if (init_stack(a, arv) != 0)
		return (cleanup_and_exit(a, b, arv, split_flag));
	if (split_flag)
		free_split(arv);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (validate_and_init(ac, av, &a, &b))
		return (1);
	checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
