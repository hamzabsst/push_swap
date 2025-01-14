/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:36:25 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 11:20:48 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	is_above_mid(t_stack *stack)
{
	int		i;
	int		mid;

	if (!stack)
		return ;
	mid = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->above_mid = 1;
		else
			stack->above_mid = 0;
		stack = stack->next;
		i++;
	}
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*current;
	int		closest_value;

	while (b)
	{
		target = NULL;
		closest_value = INT_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < closest_value)
			{
				closest_value = current->value;
				target = current;
			}
			current = current->next;
		}
		if (!target)
			target = find_min(a);
		b->target = target;
		b = b->next;
	}
}

static int	calc_cost(int index, int size, int above_mid)
{
	if (above_mid)
		return (index);
	return (size - index);
}

static int	total(int a, int b, int above_a, int above_b)
{
	if ((above_a && above_b) || (!above_a && !above_b))
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}

t_stack	*calculate_cost(t_stack *a, t_stack *b)
{
	t_stack	*stack;
	int		size_a;
	int		size_b;
	int		cost_b;
	int		cost_a;

	stack = b;
	size_a = stack_len(a);
	size_b = stack_len(b);
	while (b)
	{
		cost_b = calc_cost(b->index, size_b, b->above_mid);
		cost_a = calc_cost(b->target->index, size_a, b->target->above_mid);
		b->cost = total(cost_a, cost_b, b->above_mid, b->target->above_mid);
		b = b->next;
	}
	return (is_cheapest(stack));
}
