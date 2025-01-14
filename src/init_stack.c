/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:00:06 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 13:19:50 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	init_stack(t_stack **a, char **av)
{
	long	value;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_errors(av[i]))
			return (1);
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (1);
		if (check_duplicate(*a, (int)value))
			return (1);
		add_node(a, (int)value);
		i++;
	}
	return (0);
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
	new_node->index = -1;
	return (new_node);
}

t_stack	*is_last(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
