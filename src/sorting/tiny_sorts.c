/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:19:15 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 10:39:27 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	while (!is_sorted(*a))
	{
		first = (*a)->value;
		second = (*a)->next->value;
		third = (*a)->next->next->value;
		if (first > second && first > third)
			ra(a);
		else if (second > first && second > third)
			rra(a);
		else if (first > second)
			sa(a);
	}
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min;
	int	second_min;

	min = find_min_value(*a);
	second_min = find_second_min(*a);
	while (stack_len(*a) > 3)
	{
		if ((*a)->value == min || (*a)->value == second_min)
			pb(b, a);
		else
			ra(a);
	}
	sort_3(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

int	find_min_value(t_stack *stack)
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
	min = find_min_value(stack);
	second_min = INT_MAX;
	while (stack)
	{
		if (stack->value != min && stack->value < second_min)
			second_min = stack->value;
		stack = stack->next;
	}
	return (second_min);
}
