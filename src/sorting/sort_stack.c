/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:28:05 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 21:04:18 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!a || !(*a))
		return ;
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_3(a);
	else if (stack_len(*a) == 5)
		sort_5(a, b);
	else
		push_swap(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	t_stack	*min_node;

	while (stack_len(*a) > 3)
		push_a_to_b(a, b);
	if (!is_sorted(*a))
		sort_3(a);
	while (*b)
	{
		is_above_mid(*a);
		is_above_mid(*b);
		find_target(*a, *b);
		cheapest_node = calculate_cost(*a, *b);
		push_b_to_a(a, b, cheapest_node);
	}
	min_node = find_min(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->above_mid)
			ra(a);
		else
			rra(a);
	}
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	int	median;
	int	count;
	int	target;

	median = stack_len(*a) / 2;
	count = 0;
	target = median + 1;
	if (stack_len(*a) <= 3)
		return ;
	ranking(*a);
	while (count < target && stack_len(*a) > 3)
	{
		if ((*a)->rank <= median)
		{
			pb(b, a);
			count++;
		}
		else
			ra(a);
	}
}

void	push_b_to_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b && (*b != cheapest || *a != cheapest->target))
	{
		if (*b == cheapest && *a == cheapest->target)
			break ;
		if (*b != cheapest && *a != cheapest->target)
		{
			if (cheapest->above_mid && cheapest->target->above_mid)
				rr(a, b);
			else if (!cheapest->above_mid && !cheapest->target->above_mid)
				rrr(a, b);
			else
			{
				rotation(b, cheapest, 'b');
				rotation(a, cheapest->target, 'a');
			}
		}
		else if (*b != cheapest)
			rotation(b, cheapest, 'b');
		else
			rotation(a, cheapest->target, 'a');
	}
	pa(a, b);
}

void	rotation(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack && *stack != node)
	{
		if (node->above_mid)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}
