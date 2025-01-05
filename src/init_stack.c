/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:00:06 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/05 10:56:33 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_stack **a, char **av)
{
	long	value;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_errors(av[i]))
			free_errors(a);
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			free_errors(a);
		if (check_duplicate(*a, (int)value))
			free_errors(a);
		add_node(a, (int)value);
		i++;
	}
}

void	add_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = create_node(value);
	if (! (*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = is_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
