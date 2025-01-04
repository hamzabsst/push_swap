/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:36:25 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/04 18:44:49 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*current;

	if (a == NULL || a->next == NULL)
		return (1);
	current = a;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	indexing(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i >= median)
			stack->above_median = 0;
		else
			stack->above_median = 1;
		stack = stack->next;
		i++;
	}
}

void	is_target(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	closet_smaller;

	while (a)
	{
		closet_smaller = LONG_MIN;
		current = b;
		target = NULL;
		while (current)
		{
			if (current->value < a->value
				&& current->value > closet_smaller)
				{
					closet_smaller = current->value;
					target = current;
				}
				current = current->next;
		}
		if (closet_smaller == LONG_MIN)
			a->target = target;
		a = a->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
			a->cost = a->index;
		else
			a->cost = len_a - a->index;
		if(a->target)
		{
			if (a->target->above_median)
				a->cost = a->cost + a->target->index;
			else
				a->cost = len_b - a->target->index;
		}
		a = a->next;
	}
}

void	is_cheapest(t_stack *a)
{
	t_stack	*current;
	int		min_cost;

	if (!a)
		return ;
	min_cost = INT_MAX;
	current = a;
	while (current)
	{
		if (current->cost < min_cost)
			min_cost = current->cost;
		current = current->next;
	}
}
