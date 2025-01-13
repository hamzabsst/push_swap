/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:36:25 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/13 08:36:53 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	indexing(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		i;
	int		min;

	i = 0;
	current = stack;
	while (current)
	{
		min = INT_MAX;
		temp = stack;
		while (temp)
		{
			if (temp->value < min && temp->index == -1)
				min = temp->value;
			temp = temp->next;
		}
		temp = stack;
		while (temp)
		{
			if (temp->value == min && temp->index == -1)
			{
				temp->index = i++;
				break;
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

int	get_pivot(t_stack *stack)
{
	t_stack	*temp;
	int		size;
	int		middle;

	size = stack_len(stack);
	middle = size / 2;
	temp = stack;
	while (temp)
	{
		if (temp->index == middle)
			return (temp->value);
		temp = temp->next;
	}
	return (0);
}

void split_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;

	size = stack_len(*a);
	pushed = 0;
	while (pushed < size - 3)
	{
		if ((*a)->index < size - 3)
		{
			pb(b, a);
			pushed++;
		}
		else
		{
			ra(a);
		}
	}
}

int find_max_index(t_stack *stack)
{
	t_stack *temp = stack;
	int max_index = temp->index;

	while (temp)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return max_index;
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
