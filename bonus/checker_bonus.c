/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:20:15 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 22:46:34 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	do_double_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "rr\n"))
	{
		a = rotate(a);
		b = rotate(b);
	}
	else if (!ft_strcmp(line, "rrr\n"))
	{
		a = r_rotate(a);
		b = r_rotate(b);
	}
	else if (!ft_strcmp(line, "ss\n"))
	{
		a = swap(a);
		b = swap(b);
	}
	else
		cleanup(a, b);
}

void	do_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		push(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		push(b, a);
	else if (!ft_strcmp(line, "ra\n"))
		a = rotate(a);
	else if (!ft_strcmp(line, "rb\n"))
		b = rotate(b);
	else if (!ft_strcmp(line, "rra\n"))
		a = r_rotate(a);
	else if (!ft_strcmp(line, "rrb\n"))
		b = r_rotate(b);
	else if (!ft_strcmp(line, "sa\n"))
		a = swap(a);
	else if (!ft_strcmp(line, "sb\n"))
		b = swap(b);
	else
		do_double_command(a, b, line);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		do_command(a, b, line);
		free(line);
	}
	if (is_sorted(*a) && !*b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
