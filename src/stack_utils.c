/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:21:30 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/04 18:10:35 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*is_last(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_second_min(t_stack *stack)
{
	int		min;
	int		second_min;

	if (!stack)
		return (0);
	min = find_min(stack);
	second_min = INT_MAX;
	while (stack)
	{
		if (stack->value != min && stack->value < second_min)
			second_min = stack->value;
		stack = stack->next;
	}
	return (second_min);
}
