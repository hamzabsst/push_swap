/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:36:25 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/12 12:55:01 by hbousset         ###   ########.fr       */
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
