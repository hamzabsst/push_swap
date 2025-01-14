/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:21:30 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 10:39:13 by hbousset         ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (current == NULL || current->next == NULL)
		return (1);
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*find_min(t_stack *a)
{
	t_stack	*min;
	t_stack	*i;

	min = a;
	i = a->next;
	while (i)
	{
		if (i->value < min->value)
			min = i;
		i = i->next;
	}
	return (min);
}

t_stack	*is_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b)
	{
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

void	ranking(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	if (!stack)
		return ;
	while (current)
	{
		temp = stack;
		current->rank = 0;
		while (temp)
		{
			if (current->value > temp->value)
				current->rank++;
			temp = temp->next;
		}
		current = current->next;
	}
}
