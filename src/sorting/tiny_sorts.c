/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:19:15 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/12 13:20:18 by hbousset         ###   ########.fr       */
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

void	sort_4(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->value != min)
		ra(a);
	pb(b, a);
	if (stack_len(*a) == 3)
		sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	pushed;

	pushed = 0;
	while (stack_len(*a) > 3 && pushed < 2)
	{
		if ((*a)->value == find_min(*a) || (*a)->value == find_second_min(*a))
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
	}
	if (stack_len(*a) == 3)
		sort_3(a);
	if (stack_len(*b) == 2 && (*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;

	while (*b)
	{
		max_index = find_max_index(*b);
		bring_to_top(b, max_index);
		pa(a, b);
		if ((*a)->index > (*a)->next->index)
			ra(a);
	}
}

void	bring_to_top(t_stack **b, int target_index)
{
	int	pos;
	int	size;

	size = stack_len(*b);
	pos = find_position(*b, target_index);
	if (pos == -1)
		return;
	if (pos <= size / 2)
	{
		while ((*b)->index != target_index)
			rb(b);
	}
	else
	{
		while ((*b)->index != target_index)
				rrb(b);
	}
}

int find_position(t_stack *b, int target_index)
{
	int position = 0;

	while (b)
	{
		if (b->index == target_index)
			return (position);
		b = b->next;
		position++;
	}
	return (-1);
}
